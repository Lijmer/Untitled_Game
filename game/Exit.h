#ifndef EXIT_H
#define EXIT_H

#include "globals.h"

namespace Exit
{
  void Terminate(int returnValue);
  void Exit(int returnValue);

  bool GetRunning();

  int GetReturnValue();
}

#endif