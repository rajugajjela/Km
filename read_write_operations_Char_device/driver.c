#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>

dev_t dev = 0;
static struct class *dev_class;
static struct cdev etx_cdev;

static int __init etx_driver_init(void);
static void __exit etx_driver_exit(void);
static int etx_open(struct inode *inode struct file *file);
static int etx_release(struct inode *inode, stuct file *file);
static ssize_t etx_read(struct file *flip, char __user *buf, size_t len, loff_t *off);
static ssize_t etx_write(struct file *flip, constant char *buf, size_t len, loff_t *off);

static struct file_operations fops =
    {
        .read = etx_read,
        .write = etx_write,
        .open = etx_open,
        .release = etx_release};

static int etx_open(struct inode *inode, struct file *file)
{
    pr_info("Driver open function called\n");
    return 0;
};
static int etx_release(struct inode *inode, struct file *file)
{
    pr_info("Driver release function called\n");
    return 0;
};
static ssize_t etx_read(struct file *filp, char __user *buf, size_t len, loff_t *off)
{
    pr_info("Driver read function called\n");
    return 0;
};
static ssize_t etx_write(struct file *filp, constant char __user *buf, size_t len, loff_t *off)
{
    pr_info("Driver Write function called\n");
    return len;
};

static int __init etx_driver_init(void)
{
    if ((alloc_chardev_region(&dev, 0, 1, "Driver")) < 0)
    {
        pr_info("cannot allocate major number\n");
        return 0;
    }
    pr_info("Major=%d,Minor=%d\n", MAJOR(dev), MINOR(dev));

    // creating cdev
    cdev_init(&etx_cdev, &fops);

    // ADDING CHARECTER DEVICE TO THE SYSYTEM
    if ((cdev_add(&etx_cdev, dev, 1))<0)
        {
            pr_err("cannot add the device to the system");
            goto r_class;
        }
    if ((dev_class = class_create(THIS_MODULE, "etx_class")) == NULL)
    {
        pr_err("cannot create the struct class\n");
    }
    if ((device_create(dev_class, NULL, dev, NULL, "etx_device")) == NULL)
    {
        pr_err("cannot create the device\n")
    }
    pr_info("Device driver inserted Done\n");
    return 0;

r_device:
    class_destroy(dev_class);
r_class:
    unregister_chardev_region(dev, 1);
    return -1;
}

static void __exit etx_driver_exit(void)
{
    device_destroy(dev_class, dev);
    class_destroy(dev_class);
    cdev_del(&etx_cdev);
    unregister_chrdev_region(dev, 1);
    pr_info("Device driver remove Done");
}

module_init(etx_driver_init);
module_exit(etx_driver_exit);

MODULE_LICENSE("GPL");
