#include "Controller.h"
#include "globals.h"
namespace Controller
{
	Joystick stick[3];

	bool button[MAX_BUTTON];
	bool buttonPressed[MAX_BUTTON];
	bool buttonReleased[MAX_BUTTON];

	void InitController()
	{	
		al_install_joystick();
		al_reconfigure_joysticks();
		for(unsigned int i=0; i<MAX_BUTTON; i++)
		{
			button[i]=false;
			buttonPressed[i]=false;
			buttonReleased[i]=false;
		}
	}
	void Clean()
	{
		al_uninstall_joystick();
	}

	bool GetButton(ControllerButton ID)
	{
		return button[ID];
	}
	bool GetButtonPressed(ControllerButton ID)
	{
		return buttonPressed[ID];
	}
	bool GetButtonReleased(ControllerButton ID)
	{
		return buttonReleased[ID];
	}

	void ButtonDownEvent(const ALLEGRO_EVENT &ev)
	{
		for(int i=0; i<MAX_BUTTON; ++i)
		{
			if(ev.joystick.button == i)
			{
				button[i]=true;
				buttonPressed[i]=true;
				break;
			}
		}
	}
	void ButtonUpEvent(const ALLEGRO_EVENT &ev)
	{
		for(int i=0; i<MAX_BUTTON; ++i)
		{
			if(ev.joystick.button == i)
			{
				button[i]=false;
				buttonReleased[i]=true;
				break;
			}
		}
	}
	void AxisEvent(const ALLEGRO_EVENT &ev)
	{
		if(ev.joystick.stick == 0)
		{
			if(ev.joystick.axis == 0)
				stick[0].h_axis = ev.joystick.pos;
			else if(ev.joystick.axis == 1)
				stick[0].v_axis = ev.joystick.pos;
			else if(ev.joystick.axis == 2)		//this is very ugly, h_axis for stick1 is on stick0 :(
				stick[1].h_axis = ev.joystick.pos;
		}
		else if(ev.joystick.stick == 1)
		{
			if(ev.joystick.axis == 0)
				stick[1].v_axis = ev.joystick.pos;
		}
		else if(ev.joystick.stick == 2)
		{
			if(ev.joystick.axis == 0)
				stick[2].h_axis = ev.joystick.pos;
			else if(ev.joystick.axis == 1)
				stick[2].v_axis = ev.joystick.pos;
		}
	}
}