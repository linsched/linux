#ifndef __LINSCHED_SWITCH_TO_H
#define __LINSCHED_SWITCH_TO_H

/*
 * Saving eflags is important. It switches not only IOPL between tasks,
 * it also protects other tasks from NT leaking through sysenter etc.
 */
#define switch_to(prev, next, last)					\
do {									\
	this_cpu_write(current_task, next);				\
} while (0)

#endif
