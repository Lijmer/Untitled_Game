#ifndef GLOBALS_H
#define GLOBALS_H

#define MYDEBUG

#ifdef MYDEBUG
#include <iostream>

void PrintInBinary(int x);
#endif

const float PI = 3.14159265f;
const float FPS = 60;

#endif