#include "lib/global.h"
#include "screen/printk.h"
#include "lib/multiboot.h"
void kmain(struct multiboot *mbd, unsigned int magic )
{
	printk("Chronos Development Kernel\n");
	if (magic!=0x2BADB002)
	{
		printk("[Kernel]:Warning! Multiboot magic number isn't 0x2BADB002, it's %X\n",magic);
		printk("[Kernel Rescue]:Kernel was not booted correctly, system cannot be trusted!\n");
		printk("[Kernel]:Halting...\n");
		asm("hlt");
		while(1);
	}
	printk("[Kernel]:Initalizing Hardware...\n");
	
}
