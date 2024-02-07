#include <linux/init.h>
#include <linux/module.h>
#include <linux/platform_device.h>

int my_probe(struct platform_device *p)
{
    struct resource *my = platform_get_resource(p, IORESOURCE_IRQ, 0);
    printk("my_probe start=%ld\n", my->start);
    return 0;
}

int my_remove(struct platform_device *p)
{
    printk("my_remove");
    return 0;
}

struct platform_driver my_driver
{
    .probe = my_probe,
    .remove = my_remove,
    .driver = {
        .name = "my_device",
        .owner = THIS_MODULE},
};

static int dev_init(void)
{
    platform_driver_register(&my_driver);
    printk("hello init");
    return 0;
}

static void dev_exit(void)
{
    platform_driver_unregister(&my_driver);
    printk("hello bye");
}

module_init(dev_init);
module_exit(dev_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("MCC");
MODULE_VERSION("V1.0");
