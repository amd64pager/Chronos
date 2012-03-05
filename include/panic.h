#include <screen/printk.h>
inline void panic(const char* str)
{
	printk("->[Kernel Panic]:Panic! %s",str);
}
