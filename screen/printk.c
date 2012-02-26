#include "printk.h"
#include "vsprintf.h"
#include "../lib/stdarg.h"
#include "lwtext.h"
void printk (const char *fmt, ...)
{
        static char buf [1024];

        va_list args;
        int i;
 
        va_start(args, fmt);
        i = vsprintf(buf,fmt,args);
        va_end(args);

        buf[i] = '\0';

        puts(buf);
}
