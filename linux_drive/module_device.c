#include <linux/init.h>
#include <linux/module.h>
#include <linux/platform_device.h>

static struct resource my_resource[] = {
    [0] = {
        .start = 0xFD660000,
        .end = 0xFD660004,
        .flags = IORESOURCE_MEM},
    [1] = {.start = 13, .end = 13, .flags = IORESOURCE_IRQ},
};

void my_release(struct device *dev)
{
    printk("my_release");
}

struct platform_device my_device
{
    .name = "my_device",
    .id = -1,
    .resource = my_resource,
    .num_resources = ARRAY_SIZE(my_resource),
    .dev = {
        .release = my_release,
    }
};

static int dev_init(void)
{
    platform_device_register(&my_device);
    printk("hello init");
    return 0;
}

static void dev_exit(void)
{
    platform_device_unregister(&my_device);
    printk("hello bye");
}

module_init(dev_init);
module_exit(dev_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("MCC");
MODULE_VERSION("V1.0");
