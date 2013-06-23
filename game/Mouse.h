#ifndef MOUSE_H
#define MOUSE_H
#include <allegro5/allegro.h>
namespace Mouse
{
	void InitMouse();
	void ResetMouseButtons();

	bool GetMouseButton(unsigned int btnNum);
	bool GetMouseButtonPressed(unsigned int btnNum);
	bool GetMouseButtonReleased(unsigned int btnNum);

	float GetMouseX();
	float GetMouseY();
	
	void MouseButtonDownEvent(const ALLEGRO_EVENT &ev);
	void MouseButtonUpEvent(const ALLEGRO_EVENT &ev);
	void MouseAxesEvent(const ALLEGRO_EVENT &ev);
}

#endif