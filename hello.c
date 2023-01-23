#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/init.h>
#include<linux/sched.h>
#include <linux/printk.h>


MODULE_AUTHOR("Raju");
MODULE_DESCRIPTION("Hello World module");
MODULE_LICENSE("GPLV2");

static int hello_init(void)
{
	printk("Entering hello world module");
	printk("pid:%d\n",current->pid);
	return 0; 
}

static void hello_exit(void)
{

	printk("Exiting hello world");
}

module_init(hello_init);
module_exit(hello_exit);
