#ifndef MOUSE_H
#define MOUSE_H
#include <allegro5/allegro.h>

enum MouseButton
{
  M_LEFT=1,
  M_RIGHT=2,
  M_MIDDLE=3
};

namespace Mouse
{
  void Init();
  void ResetMouseButtons();

  bool GetMouseButton(MouseButton btnNum);
  bool GetMouseButtonPressed(MouseButton btnNum);
  bool GetMouseButtonReleased(MouseButton btnNum);
  ALLEGRO_DISPLAY* GetSelectedDisplay();

  float GetX();
  float GetY();
  float GetDX();
  float GetDY();

  void MouseButtonDownEvent(const ALLEGRO_EVENT &ev);
  void MouseButtonUpEvent(const ALLEGRO_EVENT &ev);
  void MouseAxesEvent(const ALLEGRO_EVENT &ev);
}

#endif