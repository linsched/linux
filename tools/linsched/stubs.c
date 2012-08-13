/* LinSched -- The Linux Scheduler Simulator
 * Copyright (C) 2008  John M. Calandrino
 * E-mail: jmc@cs.unc.edu
 *
 * This file contains Linux variables and functions that have been "defined
 * away" or exist here in a modified form to avoid including an entire Linux
 * source file that might otherwise lead to a "cascade" of dependency issues.
 * It also includes certain LinSched variables to which some Linux functions
 * and definitions now map.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program (see COPYING); if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include <linux/gfp.h>
#include <linux/mm.h>
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/init.h>
#include <linux/init_task.h>
#include <linux/fs.h>
#include <linux/mqueue.h>

#include <asm/uaccess.h>
#include <asm/pgtable.h>

#include <malloc.h>
void abort(void);

static int printk_level = 5; /* only show KERN_NOTICE and up */

void linsched_set_printk_level(int level)
{
	printk_level = level;
}

asmlinkage int printk(const char *fmt, ...)
{
	va_list args;
	int log_level = 5; /* default to KERN_NOTICE */

	/* very basic log_prefix handling */
	if (fmt[0] == '<' && (fmt[1] >= '0' && fmt[1] <= '9') &&
	    fmt[2] == '>') {
		log_level = fmt[1] - '0';
	}
	if (log_level > printk_level)
		return 0;

	va_start(args, fmt);
	vprintf(fmt, args);
	va_end(args);

	return 0;
}

/*
 * This doesn't care about log levels and so on, so we don't care.
 * and so this function can be simpler than printk.
 */
int printk_sched(const char *fmt, ...)
{
	va_list args;
	va_start(args, fmt);
	vprintf(fmt, args);
	va_end(args);

	return 0;
}

void panic(const char *fmt, ...)
{
	va_list args;

	va_start(args, fmt);
	vprintf(fmt, args);
	va_end(args);
	puts("");
	abort();
}

/* These functions do not copy to and from user space anymore, so
 * they are just memory copy functions now.
 */
__must_check unsigned long
_copy_from_user(void *to, const void __user * from, unsigned n)
{
	memcpy(to, from, n);
	return 0;
}

__must_check unsigned long
_copy_to_user(void __user *to, const void *from, unsigned n)
{
	memcpy(to, from, n);
	return 0;
}

void warn_slowpath_fmt(const char *file, int line, const char *fmt, ...)
{
	va_list list;
	warn_slowpath_null(file, line);
	va_start(list, fmt);
	vprintf(fmt, list);
	va_end(list);
	puts("");
}

int seq_printf(struct seq_file *m, const char *fmt, ...)
{
	va_list args;

	va_start(args, fmt);
	vprintf(fmt, args);
	va_end(args);

	return 0;
}

int seq_puts(struct seq_file *m, const char *s)
{
	puts(s);

	return 0;
}

void kfree(const void *block)
{
	free((void *)block);
}

void *__kmalloc(size_t size, gfp_t flags)
{
	void *res = malloc(size);

	if (res && (flags & __GFP_ZERO))
		memset(res, 0, size);

	return res;
}
