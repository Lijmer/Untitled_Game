#include "Controller.h"
#include "globals.h"
namespace Controller
{
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

	}
}