#ifndef __LINSCHED_ARCH_LINSCHED_H
#define __LINSCHED_ARCH_LINSCHED_H

#include <linux/sched.h>
#include <linux/cgroup.h>
#include "../../../../kernel/sched/sched.h"

#define LINSCHED_MAX_TASKS	10000
#define LINSCHED_MAX_TASKS	10000
#define LINSCHED_MAX_GROUPS	100
#define LINSCHED_MAX_GROUPS	100
extern struct task_struct *stop_tasks[NR_CPUS];
extern struct task_struct *__linsched_tasks[LINSCHED_MAX_TASKS];

struct linsched_cgroup {
	struct cgroup cg;
	void *temp;
};

extern struct linsched_cgroup __linsched_cgroups[LINSCHED_MAX_GROUPS];

struct task_data {
	void *data;
	void (*init_task) (struct task_struct *, void *data);
	void (*handle_task) (struct task_struct *, void *data);
};

struct stop_task {
	cpu_stop_fn_t fxn;
	void *arg;

	struct task_struct *p;
	struct hrtimer timer;
};
#endif
