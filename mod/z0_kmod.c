#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>

static int __init
z0_mod_init(void)
{
	pr_info("module init");

	return 0;
}

static void __exit
z0_mod_exit(void)
{
	pr_info("module exit");
}

module_init(z0_mod_init);
module_exit(z0_mod_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("0xZ3R0");
MODULE_DESCRIPTION("");
MODULE_VERSION("v0.1");
