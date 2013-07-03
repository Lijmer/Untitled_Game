#ifndef KEYBOARD_H
#define KEYBOARD_H
#include <allegro5/allegro.h>
namespace Keyboard
{
  bool GetKey(unsigned int num);
  bool GetKeyPressed(unsigned int num);
  bool GetKeyReleased(unsigned int num);

  void KeyDownEvent(const ALLEGRO_EVENT &ev);
  void KeyUpEvent(const ALLEGRO_EVENT &ev);

  void ResetKeys();
  void Init();
}
#endif