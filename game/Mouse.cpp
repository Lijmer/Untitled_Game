#include "Mouse.h"
#include <allegro5/allegro_native_dialog.h>
#include "Display.h"
#include "globals.h"
#include "Exit.h"
using Display::GetDisplay;
namespace Mouse
{
  const unsigned int mouseButtonNum = 4;
  float mouseX  = 0;
  float mouseY  = 0;
  float mouseDX = 0;
  float mouseDY = 0;
  ALLEGRO_DISPLAY* selectedDisplay = 0;

  bool mouseButton[mouseButtonNum];
  bool mouseButtonPressed[mouseButtonNum];
  bool mouseButtonReleased[mouseButtonNum];


  void Init()
  {
    static bool inited = false;
    if(inited)
    {
      al_show_native_message_box(GetDisplay(), "Mouse", "Error",
        "Mouse Init ran twice, this shouldn't have happend", 0, ALLEGRO_MESSAGEBOX_ERROR);
      Exit::Exit(1);
      return;
    }
    for(int i=0; i<mouseButtonNum; i++)
    {
      mouseButton[i]=false;
      mouseButtonPressed[i]=false;
      mouseButtonReleased[i]=false;
    }
    inited = true;
  }

  void ResetMouseButtons()
  {
    for(int i=0; i<mouseButtonNum; i++)
    {
      mouseButtonPressed[i]=false;
      mouseButtonReleased[i]=false;
    }
  }

  bool GetMouseButton(MouseButton btnNum)
  {
    return mouseButton[btnNum];
  }
  bool GetMouseButtonPressed(MouseButton btnNum)
  {
    return mouseButtonPressed[btnNum];
  }
  bool GetMouseButtonReleased(MouseButton btnNum)
  {
    return mouseButtonReleased[btnNum];
  }
  ALLEGRO_DISPLAY* GetSelectedDisplay()
  {
    return selectedDisplay;
  }

  float GetX()
  {
    return mouseX; //todo scale the mouse
  }
  float GetY()
  {
    return mouseY; //todo scale the mouse
  }
  float GetDX()
  {
    return mouseDX;
  }
  float GetDY()
  {
    return mouseDY;
  }

  void MouseButtonDownEvent(const ALLEGRO_EVENT &ev)
  {
    mouseButton[ev.mouse.button] = true;
    mouseButtonPressed[ev.mouse.button] = true;
  }
  void MouseButtonUpEvent(const ALLEGRO_EVENT &ev)
  {
    mouseButton[ev.mouse.button] = false;
    mouseButtonReleased[ev.mouse.button] = true;
  }	
  void MouseAxesEvent(const ALLEGRO_EVENT &ev)
  {
    mouseX          = ev.mouse.x;
    mouseY          = ev.mouse.y;
    mouseDX         = ev.mouse.dx;
    mouseDY         = ev.mouse.dy;
    selectedDisplay = ev.mouse.display;
  }
}