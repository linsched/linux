#ifndef __LINSCHED_PAGE_DEFS_H_
#define __LINSCHED_PAGE_DEFS_H_

#include <linux/const.h>
#include <linux/types.h>

/* PAGE_SHIFT determines the page size */
#define PAGE_SHIFT	12
#define PAGE_SIZE	(_AC(1,UL) << PAGE_SHIFT)
#define PAGE_MASK	(~(PAGE_SIZE-1))

#define PAGE_OFFSET		((unsigned long)__PAGE_OFFSET)

#define THREAD_ORDER	1
#define THREAD_SIZE  (PAGE_SIZE << THREAD_ORDER)

/*
 * Set __PAGE_OFFSET to the most negative possible address +
 * PGDIR_SIZE*16 (pgd slot 272).  The gap is to allow a space for a
 * hypervisor to fit.  Choosing 16 slots here is arbitrary, but it's
 * what Xen requires.
 */
#define __PAGE_OFFSET           _AC(0xffff880000000000, UL)

#ifndef __ASSEMBLY__
void clear_page(void *page);
void copy_page(void *to, void *from);

extern unsigned long __phys_addr(unsigned long);

#define vmemmap ((struct page *)VMEMMAP_START)

#endif	/* !__ASSEMBLY__ */

#endif	/* __LINSCHED_PAGE_DEFS_H */
