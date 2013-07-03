#include "globals.h"

//debugging functions
#ifdef MYDEBUG
void PrintInBinary(int x)
{
  static char b[9];
  b[0] = '\0';

  int z;
  for (z = 128; z > 0; z >>= 1)
  {
    strcat_s(b, ((x & z) == z) ? "1" : "0");
  }

  printf(b);
}

double diffclock(clock_t clock1, clock_t clock2)
{
  double diffticks = clock1 - clock2;
  double diffms    = (diffticks*1000)/CLOCKS_PER_SEC;
  return diffms;
}

#endif