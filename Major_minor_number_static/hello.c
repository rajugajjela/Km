#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/module.h>
#include<linux/fs.h>


dev_t dev =MKDEC(235,0);

static int __init hello_world_init(void)
{
	registwe_chrdev_region(dev,1,"My_dev");
	pr_info("Major=%d Minor=%d \n",MAJOR(dev),MINOR(dev));
	pr_info("kERNEL Module inserted successfully...\n");
	return 0;
}


static void __exit hello_world_exit(void){
	unregister_chrdev_region(dev,1);
	pr_info("Kernel remove successfully...\n");
}

module_init(hello_world_init);
module_init(hello_world_exit);


MODULE_LICENSE("GPL");
MODULE_AUTHOR("INNOMINDE");
MODULE_DESCRIPTION("SIMPLE LINUX DRIVER(STATICALLY ALLOCATING MANJPOR & MINOR NUMBERS");
MODULE_VERSION("1.0");
