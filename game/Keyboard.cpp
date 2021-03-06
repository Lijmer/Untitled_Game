#include "Keyboard.h"
#include "globals.h"
#include "Exit.h"
#include "Display.h"
#include <allegro5/allegro_native_dialog.h>

using Display::GetDisplay;

static bool key[ALLEGRO_KEY_MAX];
static bool key_pressed[ALLEGRO_KEY_MAX];
static bool key_released[ALLEGRO_KEY_MAX];
namespace Keyboard
{
  bool GetKey(unsigned int num)
  {
    if(num>=ALLEGRO_KEY_MAX)
      return false;
    return key[num];
  }
  bool GetKeyPressed(unsigned int num)
  {
    if(num>=ALLEGRO_KEY_MAX)
      return false;
    return key_pressed[num];
  }
  bool GetKeyReleased(unsigned int num)
  {
    if(num>=ALLEGRO_KEY_MAX)
      return false;
    return key_released[num];
  }

  void KeyDownEvent(const ALLEGRO_EVENT &ev)
  {
    key[ev.keyboard.keycode] = true;
    key_pressed[ev.keyboard.keycode] = true;
  }
  void KeyUpEvent(const ALLEGRO_EVENT &ev)
  {
    key[ev.keyboard.keycode] = false;
    key_released[ev.keyboard.keycode] = true;
  }

  void ResetKeys()
  {
    for(int i=0; i<ALLEGRO_KEY_MAX; i++)
    {
      key_pressed[i]=false;
      key_released[i]=false;
    }
  }
  void Init()
  {
    static bool inited = false;
    if(inited)
    {
      al_show_native_message_box(GetDisplay(), "Keyboard", "Error",
        "InitKeys ran twice", 0, ALLEGRO_MESSAGEBOX_ERROR);
      #ifdef MYDEBUG
      Exit::Exit(1);
      #endif
      return;
    }
    for(int i=0; i<ALLEGRO_KEY_MAX; i++)
    {
      key[i]=false;
      key_pressed[i]=false;
      key_released[i]=false;
    }
    inited = true;
  }
}