/*
 * This file stores all the filesystem related stubs, irrespective
 * of whether it is part of the VFS/exit routines or of some other
 * filesystem. At some point in the future we might decide to do
 * a better split, but for now, this is good enough.
 */

#include <linux/slab.h>
#include <linux/fs_struct.h>
#include <linux/fdtable.h>
#include <linux/device.h>
#include <linux/sched.h>

struct fs_struct init_fs;
struct files_struct init_files;

void free_fs_struct(struct fs_struct *fs)
{
	BUG();
}

struct fs_struct *copy_fs_struct(struct fs_struct *old)
{
	return kzalloc(sizeof(struct fs_struct), GFP_KERNEL);
}

struct files_struct *dup_fd(struct files_struct *oldf, int *errorp)
{
	return kzalloc(sizeof(struct files_struct), GFP_KERNEL);
}

void exit_fs(struct task_struct *p)
{
}

int filp_close(struct file *filp, fl_owner_t id)
{
	BUG();
	return 0;
}

void daemonize_fs_struct(void)
{
	BUG();
}

void free_fdtable_rcu(struct rcu_head *rcu)
{
	BUG();
}

void signalfd_cleanup(struct sighand_struct *sighand)
{
}

/*
 * We don't support sysfs, but need to check the consequences of this
 * decision.
 */
int device_create_file(struct device *dev,
		const struct device_attribute *attr)
{
	return 0;
}

/* kernel/sysctl.c */
int proc_dointvec(struct ctl_table *table, int write,
		  void __user *buffer, size_t *lenp, loff_t *ppos)
{
	/* should be unused */
	BUG();

	return 0;
}

int proc_dointvec_minmax(struct ctl_table *table, int write,
		    void __user *buffer, size_t *lenp, loff_t *ppos)
{
	/* should be unused */
	BUG();

	return 0;
}

struct dentry *debugfs_create_file(const char *name, mode_t mode,
				struct dentry *parent, void *data,
				const struct file_operations *fops)
{
	return NULL;
}

ssize_t seq_read(struct file *file, char *buf, size_t size, loff_t *ppos)
{
	return 0;
}

loff_t seq_lseek(struct file *file, loff_t offset, int origin)
{
	return 0;
}

int single_release(struct inode *inode, struct file *file)
{
	return 0;
}

int single_open(struct file *file, int (*show)(struct seq_file *, void *),
		void *data)
{
	return 0;
}
