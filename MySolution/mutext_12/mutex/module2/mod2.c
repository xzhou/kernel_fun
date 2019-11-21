#include <linux/module.h>
#include <linux/init.h>
#include <linux/sched.h>
#include <linux/sched/signal.h>
#include <linux/mutex.h>
#include <linux/errno.h>

extern struct mutex my_mutex;

static int __init my_init(void) {
    if (mutex_trylock(&my_mutex)) {
        pr_info("Got the lock from %s\n", KBUILD_MODNAME);
        return 0;
    } else {
        pr_info("Failed to get lock from %s\n", KBUILD_MODNAME);
        return -EBUSY;
    }
    return 0;
}

static void __exit my_exit(void) {
    mutex_unlock(&my_mutex);
    pr_info("module unloaded \n");
}

module_init(my_init);
module_exit(my_exit);
MODULE_AUTHOR("xzhou");
MODULE_LICENSE("GPL v2");

