#include <linux/sched.h>
#include <linux/nsproxy.h>
#include <linux/slab.h>

struct nsproxy init_nsproxy;

int unshare_nsproxy_namespaces(unsigned long unshare_flags,
		struct nsproxy **new_nsp, struct fs_struct *new_fs)
{
	BUG();
	return 0;
}

void switch_task_namespaces(struct task_struct *p, struct nsproxy *new)
{
	BUG();
}

void free_nsproxy(struct nsproxy *ns)
{
	BUG();
}

int __init nsproxy_cache_init(void)
{
	return 0;
}

int copy_namespaces(unsigned long flags, struct task_struct *tsk)
{
	struct nsproxy *new_ns;

	new_ns = kzalloc(sizeof(struct nsproxy), GFP_KERNEL);
	if (!new_ns)
		return -ENOMEM;

	atomic_set(&new_ns->count, 1);

	tsk->nsproxy = new_ns;

	return 0;
}

void exit_task_namespaces(struct task_struct *p)
{
}

/*
 * we don't support either namespaces or capability. So this test should
 * always return true.
 */
bool ns_capable(struct user_namespace *ns, int cap)
{
	return true;
}
