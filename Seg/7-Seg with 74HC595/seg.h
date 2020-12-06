#ifndef _SEG_H
#define _SEG_H

#include "stc15f2k60s2.h"

#define u8 unsigned char
#define u16 unsigned int

extern u8 segbuf[4];
extern u8 segcom;
extern void seg();

#endif