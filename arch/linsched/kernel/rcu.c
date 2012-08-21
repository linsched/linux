#include <linux/sched.h>

int rcu_needs_cpu(int cpu, unsigned long *delta_jiffies)
{
	return 0;
}

void rcu_enter_nohz(void)
{
}


static int init_srcu_struct_fields(struct srcu_struct *sp)
{
	BUG();
	return 0;
	//sp->completed = 0;
	//mutex_init(&sp->mutex);
	//sp->per_cpu_ref = alloc_percpu(struct srcu_struct_array);
	//return sp->per_cpu_ref ? 0 : -ENOMEM;
}
/*
 * Actually used by perf events, so let's do this one
 */
int init_srcu_struct(struct srcu_struct *sp)
{
	return init_srcu_struct_fields(sp);
}

int __srcu_read_lock(struct srcu_struct *sp)
{
	BUG();
	/*
	 * returning a magic number for now.
	 */
	return 1;
}

void __srcu_read_unlock(struct srcu_struct *sp, int idx)
{
	BUG();
}

void synchronize_srcu(struct srcu_struct *sp)
{
	BUG();
}

void rcu_check_callbacks(int cpu, int user)
{
}

void rcu_sched_qs(int cpu) {}

void rcu_exit_nohz(void)
{
}

void synchronize_sched(void)
{
}

void kfree_call_rcu(struct rcu_head *head, void (*func)(struct rcu_head *rcu))
{
	BUG();
}

void exit_rcu(void)
{
	BUG();
}
