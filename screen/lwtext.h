#ifndef MONITOR_H
#define MONITOR_H

#include "../lib/global.h"

// Write a single character out to the screen.
void putch(char c);

// Clear the screen to all black.
void screen_clear();

// Output a null-terminated ASCII string to the monitor.
void puts(char *c);

// Output a hex value to the monitor.
void puthex(u32int n);

// Output a decimal value to the monitor.
void putdec(u32int n);

#endif // MONITOR_H
