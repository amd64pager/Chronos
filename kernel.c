#include "lib/global.h"
#include "screen/lwtext.h"
#include "screen/printk.h"
#include "lib/multiboot.h"
#include "hardware/descriptor_tables.h"
#include "config.h"
void kmain(struct multiboot *mbd, unsigned int magic )
{
	if (magic!=0x2BADB002) //Check if magic number is correct
	{
		printk("[Kernel]:Warning! Multiboot magic number isn't 0x2BADB002, it's %X\n",magic);
		printk("[Kernel Rescue]:Chronos was not booted correctly, system state cannot be trusted!\n");
		printk("[Kernel]:Halting...\n");
		asm("hlt");
		while(1);
	}
	init_video();
	printk("Chronos Kernel %s (Booted by %s)\n",KERNEL_VERSION_S,mbd->boot_loader_name);
	printk("Avalable Memory:%d mb\n",mbd->mem_upper/1024);
	printk("[Kernel]:Initalizing Hardware...\n");
	init_descriptor_tables();
	printk("[GDT:IDT]:Initalized!\n");
	asm volatile ("int $0x3");
	while(1);
}
