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

    std::cout << b << std::endl;
}
#endif