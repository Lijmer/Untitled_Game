#ifndef _INCLUDED_EDITOR_DISPLAY_H
#define _INCLUDED_EDITOR_DISPLAY_H

#include <allegro5/allegro.h>

namespace EditorDisplay
{
  void CreateDisplay();
  void DestroyDisplay();
  ALLEGRO_DISPLAY* GetDisplay();
  void RedrawEditorDisplay();

  void Draw();
}


#endif