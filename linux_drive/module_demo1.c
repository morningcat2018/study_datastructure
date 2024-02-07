#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/kdev_t.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/uaccess.h>
#include <asm/uaccess.h>

dev_t dev_num;
struct cdev cdev_test;
struct class *class;
struct device *device;

static int cdev_test_open(struct inode *, struct file *)
{
    printk("cdev_test_open");
    return 0;
}

static ssize_t cdev_test_read(struct file *, char __user *buf, size_t, loff_t *)
{
    printk("cdev_test_read");
    char[32] kbuf = "a message";
    int ret = copy_to_user(buf, kbuf, strlen(kbuf));
    if (ret != 0)
    {
        printk("cdev_test_read copy_to_user error");
        return -1;
    }
    return 0;
}

struct file_operations ops = {
    .owner = THIS_MODULE,
    .open = cdev_test_open,
    .read = cdev_test_read};

static int dev_init(void)
{
    int ret = alloc_chrdev_region(&dev_num, 0, 1, "morning-dev");
    if (ret < 0)
        printk("alloc_chrdev_region is error");
    unsigned int maj = MAJOR(dev_num);
    unsigned int min = MINOR(dev_num);
    printk("maj=%d\n", maj);
    printk("min=%d\n", min);
    cdev_test.owner = THIS_MODULE;
    cdev_init(&cdev_test, &ops);
    cdev_add(&cdev_test, dev_num, 1);

    class = class_create(THIS_MODULE, "morning-device-class");
    device = device_create(class, NULL, dev_num, NULL, "morning-device");
    printk("hello init");
    return 0;
}

static void dev_exit(void)
{
    unregister_chrdev_region(dev_num, 1);
    cdev_del(&cdev_test);
    device_destroy(class, dev_num);
    class_destroy(class);
    printk("hello bye");
}

module_init(dev_init);
module_exit(dev_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("MCC");
MODULE_VERSION("V1.0");
