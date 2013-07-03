#ifndef DISP_H
#define DISP_H

#include <allegro5/allegro.h>

const int _SW = 800;
const int _SH = 600;

namespace Display
{
  void CreateDisplay();
  void InitIcon();
  void DestroyDisplay();
  ALLEGRO_DISPLAY* GetDisplay();

  int GetMonitorWidth();
  int GetMonitorHeight();
}
#endif