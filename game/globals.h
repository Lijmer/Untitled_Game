#ifndef GLOBALS_H
#define GLOBALS_H

#define MYDEBUG

#ifdef MYDEBUG
#include <iostream>
#include <cstdio>
#include <ctime>
void PrintInBinary(int x);
double diffclock(clock_t clock1, clock_t clock2);
#endif

const double PI        = 3.141592653589793;
const double TAU       = PI*2.0;
const float  FPSTarget = 60;

#endif