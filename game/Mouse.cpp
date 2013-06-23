#include "Mouse.h"
#include <allegro5/allegro_native_dialog.h>
#include "Display.h"
#include "globals.h"
#include "Exit.h"
using Display::GetDisplay;
namespace Mouse
{
	const unsigned int mouseButtonNum = 3;
	float mouseX = 0;
	float mouseY = 0;

	bool mouseButton[mouseButtonNum];
	bool mouseButtonPressed[mouseButtonNum];
	bool mouseButtonReleased[mouseButtonNum];

	void InitMouse()
	{
		static bool inited = false;
		if(inited)
		{
			al_show_native_message_box(GetDisplay(), "Mouse", "Error",
				"Mouse Init ran twice, this shouldn't have happend", 0, ALLEGRO_MESSAGEBOX_ERROR);
			#ifdef MYDEBUG
			Exit::Exit(1);
			#endif
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

	bool GetMouseButton(unsigned int btnNum)
	{
		if(btnNum>=mouseButtonNum)
		{
			al_show_native_message_box(GetDisplay(), "Mouse", "Error",
				"btnNum is out of range", 0, ALLEGRO_MESSAGEBOX_ERROR);
			return false;
		}
		return mouseButton[btnNum];
	}
	bool GetMouseButtonPressed(unsigned int btnNum)
	{
		if(btnNum>=mouseButtonNum)
		{
			al_show_native_message_box(GetDisplay(), "Mouse", "Error",
				"btnNum is out of range", 0, ALLEGRO_MESSAGEBOX_ERROR);
			return false;
		}
		return mouseButtonPressed[btnNum];
	}
	bool GetMouseButtonReleased(unsigned int btnNum)
	{
		if(btnNum>=mouseButtonNum)
		{
			al_show_native_message_box(GetDisplay(), "Mouse", "Error",
				"btnNum is out of range", 0, ALLEGRO_MESSAGEBOX_ERROR);
			return false;
		}
		return mouseButtonPressed[btnNum];
	}

	float GetMouseX()
	{
		return mouseX; //todo scale the mouse
	}
	float GetMouseY()
	{
		return mouseY; //todo scale the mouse
	}

	void MouseButtonDownEvent(const ALLEGRO_EVENT &ev)
	{
		for(unsigned int i=0; i<mouseButtonNum; i++)
		{
			if(ev.mouse.button == i)
			{
				mouseButton[i]=true;
				mouseButtonPressed[i]=true;
				break;
			}
		}
	}
	void MouseButtonUpEvent(const ALLEGRO_EVENT &ev)
	{
		for(unsigned int i=0; i<mouseButtonNum; i++)
		{
			if(ev.mouse.button == i)
			{
				mouseButton[i]=false;
				mouseButtonReleased[i]=true;
				break;
			}
		}
	}	
	void MouseAxesEvent(const ALLEGRO_EVENT &ev)
	{
		mouseX = ev.mouse.dx;
		mouseY = ev.mouse.dy;
	}
}