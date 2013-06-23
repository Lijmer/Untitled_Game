#include "globals.h"

#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>

#include "Display.h"
#include "Audio.h"
#include "Bitmap.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "Exit.h"

using namespace Display;
using namespace Audio;
using namespace Keyboard;
using namespace Mouse;

bool redraw = true;

void InitAllegro();
void InstallAddons();
void InitEvents();
void HandleEvent(ALLEGRO_EVENT &ev);
void TimerEvent();
void Draw();
void Clean();

ALLEGRO_EVENT_QUEUE *event_queue = 0;
ALLEGRO_TIMER *timer             = 0;

int main()
{
	InitAllegro();
	CreateDisplay();
	InstallAddons();
	InitEvents();
	while(Exit::GetRunning())
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);
		HandleEvent(ev);
		if(redraw && al_is_event_queue_empty(event_queue))
			Draw();
	}
	Clean();
	return 0;
}

void InitAllegro()
{
	if(!al_init())
	{
		al_show_native_message_box(0, "Main", "Error", "Failed to init allegro", 0,ALLEGRO_MESSAGEBOX_ERROR);
		Exit::Terminate(-1);
	}
}
void InstallAddons()
{
	al_install_keyboard();
	al_install_mouse();
	al_init_primitives_addon();
	InitAudio();	
	InitKeyboard();
	InitMouse();
}
void InitEvents()
{
	event_queue = al_create_event_queue();

	timer = al_create_timer(1./FPS);
	al_start_timer(timer);

	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_mouse_event_source());
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
	else if(ev.type == ALLEGRO_EVENT_TIMER)
		TimerEvent();
	else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		Exit::Exit(0);
}
void TimerEvent()
{
	redraw = true;
	//todo: place update stuff here
	ResetKeys();
	ResetMouseButtons();
}
void Draw()
{
	redraw = false;
	
	al_set_target_backbuffer(GetDisplay());
	al_clear_to_color(al_map_rgb(0,0,0));

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
}
