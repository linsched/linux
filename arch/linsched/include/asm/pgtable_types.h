#ifndef _ASM_LINSCHED_PGTABLE_DEFS_H
#define _ASM_LINSCHED_PGTABLE_DEFS_H

#define PAGETABLE_LEVELS	0

/* See Documentation/x86/x86_64/mm.txt for a description of the memory map. */
#define VMEMMAP_START	 _AC(0xffffea0000000000, UL)

#include <linux/types.h>

/*
 * These are used to make use of C type-checking..
 */
typedef unsigned long	pteval_t;
typedef unsigned long	pmdval_t;
typedef unsigned long	pudval_t;
typedef unsigned long	pgdval_t;
typedef unsigned long	pgprotval_t;

typedef struct { pteval_t pte; } pte_t;

typedef struct pgprot { pgprotval_t pgprot; } pgprot_t;

typedef struct { pgdval_t pgd; } pgd_t;

#include <asm-generic/pgtable-nopud.h>
#include <asm-generic/pgtable-nopmd.h>

#define pgprot_val(x)	((x).pgprot)
#define __pgprot(x)	((pgprot_t) { (x) } )

typedef struct page *pgtable_t;

#endif /* _ASM_LINSCHED_PGTABLE_DEFS_H */
