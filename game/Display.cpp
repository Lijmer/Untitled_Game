#include "Display.h"
#include "globals.h"
#include "Exit.h"
#include <allegro5/allegro_native_dialog.h>
namespace Display
{
  ALLEGRO_DISPLAY_MODE  disp_data;
  ALLEGRO_DISPLAY      *display   = 0;
  ALLEGRO_BITMAP       *icon      = 0;

  void CreateDisplay()
  {
    static bool displayCreated = false;

    if(displayCreated)
    {
      al_show_native_message_box(0, "Display", "Error",
        "Display is created twice", 0, ALLEGRO_MESSAGEBOX_ERROR);
      return;
    }

    al_get_display_mode(al_get_num_display_modes()-1, &disp_data);
    display = al_create_display(_SW,_SH);
    

    if(display == 0)
    {
      al_show_native_message_box(0, "Display", "Error",
        "Failed to create display", 0, ALLEGRO_MESSAGEBOX_ERROR);
      Exit::Terminate(1);
      return;
    }

    displayCreated = true;
  }

  void InitIcon()
  {
    icon = al_load_bitmap("icon.png");
    if(!icon)
    {
      al_show_native_message_box(display, "Display", "Error", 
        "Failed to load icon.", 0, ALLEGRO_MESSAGEBOX_ERROR);
    }
    al_set_display_icon(display, icon);
  }

  void DestroyDisplay()
  {
    if(icon)
      al_destroy_bitmap(icon);
    if(display)
      al_destroy_display(display);
  }
  ALLEGRO_DISPLAY* GetDisplay()
  {
    return display;
  }

  int GetMonitorWidth()
  {
    return disp_data.width;
  }
  int GetMonitorHeight()
  {
    return disp_data.height;
  }
}