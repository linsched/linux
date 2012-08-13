#include <linux/sched.h>
#include <linux/slab.h>
#include <linux/fs_struct.h>
#include <linux/module.h>
#include <linux/nsproxy.h>
#include <linux/device.h>
#include <linux/fdtable.h>
#include <linux/personality.h>

#include <linux/clocksource.h>
#include <linux/syscore_ops.h>

#include <linux/init.h>
#include <linux/init_task.h>
#include <asm/irq_regs.h>

struct group_info init_groups = {.usage = ATOMIC_INIT(2) };

struct percpu_counter vm_committed_as;

/* needs correct initialization depending on core speeds */
unsigned int cpu_khz;
struct task_struct *kthreadd_task;

struct user_struct root_user;
struct exec_domain default_exec_domain;

unsigned long current_address;

DEFINE_PER_CPU(int, dirty_throttle_leaks) = 0;

void prop_local_destroy_single(struct prop_local_single *pl)
{
}

int prop_local_init_single(struct prop_local_single *pl)
{
	return 0;
}

long sys_futex(u32 *uaddr, int op, u32 val, struct timespec *utime,
		u32 uaddr2, u32 val3)
{
       /* returning non-zero, but should test this */
	return 1;
}

enum hrtimer_restart it_real_fn(struct hrtimer *time)
{
	return HRTIMER_NORESTART;
}

int copy_thread(unsigned long clone_flags, unsigned long sp,
		unsigned long unused, struct task_struct *p,
		struct pt_regs *regs)
{
	return 0;
}

void recalc_sigpending(void)
{
}

void __ptrace_link(struct task_struct *child, struct task_struct *new_parent)
{
}

bool task_set_jobctl_pending(struct task_struct *task, unsigned int mask)
{
	return true;
}

void ptrace_notify(int exit_code)
{
}

int send_sig(int sig, struct task_struct *p, int priv)
{
	return 0;
}

void mod_zone_page_state(struct zone *zone, enum zone_stat_item item, int i)
{
}

int printk_needs_cpu(int cpu)
{
	return 0;
}

void vmalloc_sync_all(void)
{
	BUG();
}

void clocksource_resume(void)
{
	BUG();
}

void clocksource_suspend(void)
{
	BUG();
}

void register_syscore_ops(struct syscore_ops *ops)
{
	BUG();
}

void
clocks_calc_mult_shift(u32 *mult, u32 *shift, u32 from, u32 to, u32 maxsec)
{
	BUG();
}

int clocksource_register(struct clocksource *cs)
{
	BUG();
	return 0;
}

int zap_other_threads(struct task_struct *p)
{
	BUG();
	return 0;
}

void proc_clear_tty(struct task_struct *p)
{
	BUG();
}

void flush_signals(struct task_struct *t)
{
	BUG();
}

int __kill_pgrp_info(int sig, struct siginfo *info, struct pid *pgrp)
{
	return 0;
}

/*
 * Might need the lock annotations
 */
void exit_ptrace(struct task_struct *tracer)
{
}

int group_send_sig_info(int sig, struct siginfo *info, struct task_struct *p)
{
	return 0;
}

void exit_irq_thread(void)
{
}

void exit_signals(struct task_struct *tsk)
{
}

void acct_collect(long exitcode, int group_dead)
{
}

void exit_thread(void)
{
}

void __free_pipe_info(struct pipe_inode_info *pipe)
{
}

void exit_itimers(struct signal_struct *sig)
{
}

void acct_process(void)
{
}

void disassociate_ctty(int on_exit)
{
}

void printk_tick(void)
{
}

unsigned int alarm_setitimer(unsigned int seconds)
{
	BUG();
	return 0;
}

void si_meminfo(struct sysinfo *val)
{
	BUG();
}

void si_swapinfo(struct sysinfo *val)
{
	BUG();
}

bool ptrace_may_access(struct task_struct *task, unsigned int mode)
{
	BUG();
	return true;
}

void exit_robust_list(struct task_struct *curr)
{
}

void exit_pi_state_list(struct task_struct *curr)
{
}

/* kernel/dumpstack.c */
void show_stack(struct task_struct *task, unsigned long *sp)
{
	/* should be unused */
	BUG();
}

/* kernel/blk-core.c */
void blk_flush_plug_list(struct blk_plug *plug, bool from_schedule)
{
	/* should be unused */
	BUG();
}

int tsk_fork_get_node(struct task_struct *tsk)
{
	return numa_node_id();
}

long do_no_restart_syscall(struct restart_block *param)
{
	return -EINTR;
}

int security_task_setnice(struct task_struct *p, int nice)
{
	return 0;
}

int __printk_ratelimit(const char *func)
{
	return 0;
}

void enter_idle(void)
{
}

void __exit_idle(void)
{
}

void exit_idle(void)
{
}

void dump_stack(void)
{
}

struct sighand_struct *__lock_task_sighand(struct task_struct *tsk,
					 unsigned long *flags)
{
	return tsk->sighand;
}

void copy_from_user_overflow(void)
{
}

void user_disable_single_step(struct task_struct *child)
{
}

void warn_slowpath_null(const char *file, int line)
{
	printk("WARNING: at %s:%d\n", file, line);
}

void kprobe_flush_task(struct task_struct *tk)
{
}

void put_callchain_buffers(void)
{
}

/*
 * Needed by perf events, we can get away with this because we don't
 * have any userspace.
 */
struct file *fget_light(unsigned int fd, int *fput_needed)
{
	BUG();
	return NULL;
}

void free_uid(struct user_struct *up)
{
	BUG();
}

int fasync_helper(int fd, struct file * filp, int on, struct fasync_struct **fapp)
{
	BUG();
	return 0;
}

void kill_fasync(struct fasync_struct **fp, int sig, int band)
{
	BUG();
}

struct perf_callchain_entry *perf_callchain(struct pt_regs *regs)
{
	BUG();
	return NULL;
}

char *d_path(const struct path *path, char *buf, int buflen)
{
	BUG();
	return NULL;
}

const char *arch_vma_name(struct vm_area_struct *vma)
{
	return NULL;
}

void *dev_get_drvdata(const struct device *dev)
{
	return NULL;
}

void device_initialize(struct device *dev)
{
	BUG();
}

int dev_set_name(struct device *dev, const char *fmt, ...)
{
	BUG();
	return 0;
}

int dev_set_drvdata(struct device *dev, void *data)
{
	BUG();
	return 0;
}

int device_add(struct device *dev)
{
	BUG();
	return 0;
}

void put_device(struct device *dev)
{
	BUG();
}

void device_del(struct device *dev)
{
	BUG();
}

int get_callchain_buffers(void)
{
	BUG();
	return 0;
}

int alloc_fd(unsigned start, unsigned flags)
{
	BUG();
	return 0;
}

struct file *anon_inode_getfile(const char *name,
		const struct file_operations *fops,
		void *priv, int flags)
{
	BUG();
	return NULL;
}

void fd_install(unsigned int fd, struct file *file)
{
	BUG();
}

void put_unused_fd(unsigned int fd)
{
	BUG();
}

/*
 * Since linsched is a simulator, where we cannot really "reboot"/shutdown
 * we do not need these notifiers. Just do nothing in that case.
 */
int register_reboot_notifier(struct notifier_block *nb)
{
	return 0;
}

int __bus_register(struct bus_type *bus, struct lock_class_key *key)
{
	BUG();
	return 0;
}

/*
 * Does this leave leaks? Maybe we should test this at some point in time.
 */
void free_pages(unsigned long addr, unsigned int order)
{
	BUG();
}

bool __get_page_tail(struct page *page)
{
	BUG();
	return false;
}

struct page *
__alloc_pages_nodemask(gfp_t gfp_mask, unsigned int order,
		struct zonelist *zonelist, nodemask_t *nodemask)
{
	struct page *page;
	BUG();
	page = kzalloc(sizeof(struct page), gfp_mask);
	return page;
}

void __free_pages(struct page *page, unsigned int order)
{
	BUG();
	kfree(page);
}

loff_t no_llseek(struct file *file, loff_t offset, int origin)
{
	        return -ESPIPE;
}

void add_taint(unsigned flag)
{
	BUG();
}

/*
 * We don't handle the kernel command line (yet)
 */
int get_option(char **str, int *pint)
{
	BUG();
	return 0;
}

void task_work_run(void)
{
	BUG();
}
