#ifndef MONITOR_H
#define MONITOR_H

#include "../lib/global.h"

void init_video();
// Write a single character out to the screen.
void putch(char c);

// Clear the screen to all black.
void screen_clear();

// Output a null-terminated ASCII string to the monitor.
void puts(char *c);
#endif // MONITOR_H
