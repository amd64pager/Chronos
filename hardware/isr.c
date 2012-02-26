#include "../lib/global.h"
#include "isr.h"
#include "../screen/printk.h"

// This gets called from our ASM interrupt handler stub.
void isr_handler(registers_t regs)
{
	printk("Recieved Interrupt: %X\n",regs.int_no);
}
