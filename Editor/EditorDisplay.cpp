#include "EditorDisplay.h"
#include <allegro5/allegro_native_dialog.h>
#include "Display.h"
#include "Exit.h"
namespace EditorDisplay
{
  ALLEGRO_DISPLAY *display = 0;
  bool redraw = true;
  void CreateDisplay()
  {
    al_set_new_display_flags(ALLEGRO_WINDOWED);
    display = al_create_display(200, 400);
    if(!display)
    {
      al_show_native_message_box(0, "EditorDisplay", "Error",
        "Failed to create editor display", 0, 0);
      Exit::Exit(1);
    }

    int x=0;
    int y=0;
    al_get_window_position(Display::GetDisplay(), &x, &y);
    al_set_window_position(display, x-209, y-25);
    
  }
  void DestroyDisplay()
  {
    if(display)
      al_destroy_display(display);
  }
  ALLEGRO_DISPLAY* GetDisplay()
  {
    return display;
  }

  void RedrawEditorDisplay()
  {
    redraw = true;
  }

  void Draw()
  {
    if(!redraw)
      return;
    redraw = false;

    al_set_target_backbuffer(display);

    al_flip_display();
  }
}