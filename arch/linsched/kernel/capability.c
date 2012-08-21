#include <linux/sched.h>

/*
 * We don't support capabilities.
 */
int cap_settime(const struct timespec *ts, const struct timezone *tz)
{
	BUG();
	return 0;
}

/* kernel/capability.c */
bool task_ns_capable(struct task_struct *t, int cap)
{
	return true;
}

bool capable(int cap)
{
	return 1;
}

int cap_task_setnice(struct task_struct *p, int nice)
{
	return 1;
}

int cap_task_setscheduler(struct task_struct *p, int policy,
			struct sched_param *lp)
{
	return 1;
}
