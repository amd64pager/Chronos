#include <screen/printk.h>
#ifndef GLOBAL_H
typedef unsigned int   u32int;
typedef          int   s32int;
typedef unsigned short u16int;
//typedef          short s16int;
//typedef unsigned char  u8int;
//typedef          char  s8int;
#endif
u16int *video_memory = (u16int*)0xB8000;
inline void panic(const char* str, int ku)
{
	if(!ku)
	{
		printk("##[Kernel Panic]:Panic! %s",str);
	}
	else
	{
		printk("KU[Kernel Panic]:Panic! %s",str);
		__fallback();
	}
}
void __fallback()
{
	asm("cli");
	asm("hlt");
	while(true);;
}