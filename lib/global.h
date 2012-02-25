//The Global Header, provides core functions and typedef's
#ifndef GLOBAL_H
#define GLOBAL_H
typedef unsigned int   u32int;
typedef          int   s32int;
typedef unsigned short u16int;
typedef          short s16int;
typedef unsigned char  u8int;
typedef          char  s8int;

void koutb(u16int port, u8int value);
u8int kinb(u16int port);
u16int kinw(u16int port);
#endif
