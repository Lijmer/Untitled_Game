#ifndef _INCLUDED_EDITOR_H
#define _INCLUDED_EDITOR_H
#include "globals.h"

namespace Editor
{
  void Init(); //Create UI for editor


  void PlaceObject();
  void RemoveObject();
  void MoveObject();            //left mouse button + control
  void SelectObject();

  void Draw();

}

#endif //ifndef INCLUDED_EDITOR_H