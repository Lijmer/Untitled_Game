#include "globals.h"

#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>

#include "Display.h"
#include "Audio.h"
#include "Bitmap.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "Controller.h"
#include "Exit.h"

#include "objManager.h"

using namespace Display;
using namespace Audio;
using namespace Keyboard;
using namespace Mouse;

void InitAllegro();
void SetInformation();
void InstallAddons();
void InitEvents();
void HandleEvent(ALLEGRO_EVENT &ev);
void TimerEvent();
void Draw();
void Clean();

bool                 redraw      = true;
ALLEGRO_EVENT_QUEUE *event_queue = 0;
ALLEGRO_TIMER       *timer       = 0;

int main()
{
	InitAllegro();
	SetInformation();
	CreateDisplay();
	InstallAddons();
	InitEvents();

	Bitmap::LoadBitmap(Bitmap::IMG_TEST);
	objManager::CreateObject(objManager::OBJ_TEST, _SW/2, _SH/2, 0, 0);

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
		al_show_native_message_box(0, "Main", "Error", "Failed to init allegro", 0,ALLEGRO_MESSAGEBOX_ERROR);
		Exit::Terminate(-1);
	}
}
void SetInformation()
{
	al_set_app_name("Untitled Game");
	al_set_org_name("Max Oomen");

	#ifdef MYDEBUG //print out the info when debugging
	std::cout << al_get_org_name() << std::endl << al_get_app_name() << std::endl;
	for(int i=0; i<ALLEGRO_LAST_PATH; ++i)
	{
		ALLEGRO_PATH *a = al_get_standard_path(i);
		
		std::cout << al_path_cstr(a, ALLEGRO_NATIVE_PATH_SEP) << std::endl;
	}
	#endif
}
void InstallAddons()
{
	al_install_keyboard();
	al_install_mouse();
	al_init_primitives_addon();
	InitAudio();
	Bitmap::InitBitmaps();
	InitKeyboard();
	InitMouse();
	Controller::InitController();
}
void InitEvents()
{
	event_queue = al_create_event_queue();

	timer = al_create_timer(1./FPS);
	al_start_timer(timer);

	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_mouse_event_source());
	al_register_event_source(event_queue, al_get_joystick_event_source());
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_display_event_source(GetDisplay()));
}
void HandleEvent(ALLEGRO_EVENT &ev)
{
	if(ev.type == ALLEGRO_EVENT_KEY_DOWN)
		KeyDownEvent(ev);
	else if(ev.type == ALLEGRO_EVENT_KEY_UP)
		KeyUpEvent(ev);
	else if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
		MouseButtonDownEvent(ev);
	else if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
		MouseButtonUpEvent(ev);
	else if(ev.type == ALLEGRO_EVENT_MOUSE_AXES)
		MouseAxesEvent(ev);
	else if(ev.type == ALLEGRO_EVENT_JOYSTICK_BUTTON_DOWN)
		Controller::ButtonDownEvent(ev);
	else if(ev.type == ALLEGRO_EVENT_JOYSTICK_BUTTON_UP)
		Controller::ButtonUpEvent(ev);
	else if(ev.type == ALLEGRO_EVENT_JOYSTICK_AXIS)
		Controller::AxisEvent(ev);
	else if(ev.type == ALLEGRO_EVENT_TIMER)
		TimerEvent();
	else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		Exit::Exit(0);
}
void TimerEvent()
{
	redraw = true;

	if(Keyboard::GetKey(ALLEGRO_KEY_ESCAPE))
		Exit::Exit(0);

	objManager::Update();
	ResetKeys();
	ResetMouseButtons();
}
void Draw()
{
	redraw = false;
	
	al_set_target_backbuffer(GetDisplay());
	al_clear_to_color(al_map_rgb(0,0,0));
	al_draw_line(0,_SH/2,_SW,_SH/2, al_map_rgb(255,255,255), 1);
	al_draw_line(_SW/2,0,_SW/2,_SH, al_map_rgb(255,255,255), 1);
	objManager::Draw();
	al_flip_display();
}
void Clean()
{
	if(event_queue!=0)
		al_destroy_event_queue(event_queue);
	if(timer!=0)
		al_destroy_timer(timer);
	al_uninstall_keyboard();
	al_uninstall_mouse();
	al_shutdown_primitives_addon();
	DestroyAudio();
	Controller::Clean();
	al_uninstall_system();
}
