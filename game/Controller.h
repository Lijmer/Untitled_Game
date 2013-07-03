#ifndef _INCLUDE_CONTROLLER_H
#define _INCLUDE_CONTROLLER_H

#include <allegro5/allegro.h>

namespace Controller
{
  struct Joystick
  {
    float h_axis;
    float v_axis;
  };

  enum ControllerButton
  {
    TRIANGLE,
    CIRCLE,
    CROSS,
    SQUARE,
    L1,
    R1,
    L2,
    R2,
    SELECT,
    START,
    L3,
    R3
  };
  const int MAX_BUTTON = 12;
  void Init();
  void Clean();
  bool GetButton(ControllerButton ID);
  bool GetButtonPressed(ControllerButton ID);
  bool GetButtonReleased(ControllerButton ID);

  void ButtonDownEvent(const ALLEGRO_EVENT &ev);
  void ButtonUpEvent(const ALLEGRO_EVENT &ev);
  void AxisEvent(const ALLEGRO_EVENT &ev);
}




#endif