#include "globals.h"

#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>

#include "Display.h"
#include "Audio.h"
#include "Bitmap.h"
#include "Text.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "Controller.h"
#include "Exit.h"

#include "objManager.h"

#include "Editor.h"
#include "EditorDisplay.h"

using Display::GetDisplay;

void InitAllegro();
void SetInformation();
void InstallAddons();
void InitComponents();
void InitEvents();
void HandleEvent(ALLEGRO_EVENT &ev);
void TimerEvent();
void EditorTimerEvent();
void UpdateFPS();
void Draw();
void Clean();

void InitEditor();

double               gameTime    = 0;
double               currentFPS  = 0;
bool                 redraw      = true;
ALLEGRO_EVENT_QUEUE *event_queue = 0;
ALLEGRO_TIMER       *timer       = 0;
ALLEGRO_TIMER       *editorTimer = 0;

int main()
{
  InitAllegro();
  SetInformation();
  Display::CreateDisplay();
  EditorDisplay::CreateDisplay();
  InstallAddons();
  InitComponents();
  gameTime = al_current_time();
  InitEvents();  
  InitEditor();

  while(Exit::GetRunning())
  {
    ALLEGRO_EVENT ev;
    al_wait_for_event(event_queue, &ev);
    HandleEvent(ev);
    if(redraw && al_is_event_queue_empty(event_queue))
      Draw();
  }
  Clean();
  return Exit::GetReturnValue();
}

void InitAllegro()
{
  if(!al_init())
  {
    al_show_native_message_box(0, "Main", "Error",
      "Failed to init allegro", 0,ALLEGRO_MESSAGEBOX_ERROR);
    Exit::Terminate(-1);
  }
}
void SetInformation()
{
  al_set_app_name("Untitled Game");
  al_set_org_name("Max Oomen");

  #ifdef MYDEBUG //print out the info when debugging
  printf("%s\n%s\n", al_get_org_name(), al_get_app_name());
  for(int i=0; i<ALLEGRO_LAST_PATH; ++i)
  {
    ALLEGRO_PATH *path = al_get_standard_path(i);
    printf("%s\n", al_path_cstr(path, ALLEGRO_NATIVE_PATH_SEP));
  }
  #endif
}
void InstallAddons()
{
  al_install_keyboard();
  al_install_mouse();
  al_init_primitives_addon();
}
void InitComponents()
{
  Audio::Init();
  Bitmap::Init();
  Display::InitIcon();
  Text::Init();

  Keyboard::Init();
  Mouse::Init();
  Controller::Init();

  objManager::Init();
}
void InitEvents()
{
  event_queue = al_create_event_queue();

  timer = al_create_timer(1./FPSTarget);
  editorTimer = al_create_timer(1./5.);
  al_start_timer(timer);
  al_start_timer(editorTimer);

  al_register_event_source(event_queue, al_get_keyboard_event_source());
  al_register_event_source(event_queue, al_get_mouse_event_source());
  al_register_event_source(event_queue, al_get_joystick_event_source());
  al_register_event_source(event_queue, al_get_timer_event_source(timer));
  al_register_event_source(event_queue, al_get_timer_event_source(editorTimer));
  al_register_event_source(event_queue, al_get_display_event_source(GetDisplay()));
}
void HandleEvent(ALLEGRO_EVENT &ev)
{
  if(ev.type == ALLEGRO_EVENT_KEY_DOWN)
    Keyboard::KeyDownEvent(ev);
  else if(ev.type == ALLEGRO_EVENT_KEY_UP)
    Keyboard::KeyUpEvent(ev);
  else if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
    Mouse::MouseButtonDownEvent(ev);
  else if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
    Mouse::MouseButtonUpEvent(ev);
  else if(ev.type == ALLEGRO_EVENT_MOUSE_AXES)
    Mouse::MouseAxesEvent(ev);
  else if(ev.type == ALLEGRO_EVENT_JOYSTICK_BUTTON_DOWN)
    Controller::ButtonDownEvent(ev);
  else if(ev.type == ALLEGRO_EVENT_JOYSTICK_BUTTON_UP)
    Controller::ButtonUpEvent(ev);
  else if(ev.type == ALLEGRO_EVENT_JOYSTICK_AXIS)
    Controller::AxisEvent(ev);
  else if(ev.type == ALLEGRO_EVENT_TIMER && ev.timer.source == timer)
    TimerEvent();
  else if(ev.type == ALLEGRO_EVENT_TIMER && ev.timer.source == editorTimer)
    EditorTimerEvent();
  else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
    Exit::Exit(0);
}
void TimerEvent()
{
  redraw = true;
  if(Keyboard::GetKey(ALLEGRO_KEY_ESCAPE))
    Exit::Exit(0);

  if(Mouse::GetSelectedDisplay() == Display::GetDisplay() && 
    Mouse::GetX() >= 0 && Mouse::GetX() <= _SW &&
    Mouse::GetY() >= 0 && Mouse::GetY() <= _SH)
   {
    if(Keyboard::GetKey(ALLEGRO_KEY_LSHIFT))
    {
      if(Mouse::GetMouseButton(M_LEFT))
        Editor::PlaceObject();    
      else if(Mouse::GetMouseButton(M_RIGHT))
        Editor::RemoveObject();
    }
    else if(Keyboard::GetKey(ALLEGRO_KEY_LCTRL))
    {
      if(Mouse::GetMouseButtonPressed(M_LEFT))
        Editor::SelectObject();
      else if(Mouse::GetMouseButton(M_LEFT))
        Editor::MoveObject();
    }
    else
    {
      if(Mouse::GetMouseButtonPressed(M_LEFT))
        Editor::PlaceObject();
      else if(Mouse::GetMouseButtonPressed(M_RIGHT))
        Editor::RemoveObject();
    }
  }
  objManager::Update();
  Keyboard::ResetKeys();
  Mouse::ResetMouseButtons();
}
void EditorTimerEvent()
{
  EditorDisplay::RedrawEditorDisplay();
}
void UpdateFPS()
{
  static int frames = 0;
  ++frames;
  if(al_current_time() - gameTime >= 1)
  {
    gameTime   = al_current_time();
    currentFPS = frames;
    frames     = 0;
  }
}
void Draw()
{
  redraw = false;

  UpdateFPS();

  al_set_target_backbuffer(GetDisplay());
  al_clear_to_color(al_map_rgb(0,0,0));
  objManager::Draw();
  Editor::Draw();
  #ifdef MYDEBUG
  Text::DrawTextOutline(Text::NOKIA_FONT, al_map_rgb(255,255,255),
    al_map_rgb(0,0,255), 20, 20, 1, 0, "FPS: %f", currentFPS);
  #endif
  al_flip_display();

  EditorDisplay::Draw();
}
void Clean()
{
  objManager::DestroyAllObjects();

  if(event_queue!=0)
    al_destroy_event_queue(event_queue);
  if(timer!=0)
    al_destroy_timer(timer);
  al_uninstall_keyboard();
  al_uninstall_mouse();
  al_shutdown_primitives_addon();
  Audio::DestroyAudio();
  Controller::Clean();
  Display::DestroyDisplay();
  EditorDisplay::DestroyDisplay();
  al_uninstall_system();
}

void InitEditor()
{
  Editor::Init();
}
