#ifndef KHEAP_H
#define KHEAP_H
u32int kmalloc(u32int sz);
u32int kmalloc_p(u32int sz, u32int *phys);
u32int kmalloc_ap(u32int sz, u32int *phys);

#endif
