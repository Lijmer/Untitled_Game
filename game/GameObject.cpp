#include "GameObject.h"
#include <allegro5/allegro_native_dialog.h>
#include "Display.h"

GameObject::GameObject(void)
{
	x=0;
	y=0;
	velX=0;
	velY=0;

	ID = 0;
	collidable=true;
	depth = 0;
}


GameObject::~GameObject(void)
{
}

void GameObject::Init(float x, float y, float velX, float velY)
{
	GameObject::x    = x;
	GameObject::y    = y;
	GameObject::velX = velX;
	GameObject::velY = velY;
}
void GameObject::Update()
{

}
void GameObject::Draw()
{

}
void GameObject::Destroy()
{

}

bool GameObject::CheckCollision(GameObject *other)
{
	DerivedMaskPointer DerivedMask = *(other->GetDerivedMask());
	if(DerivedMask.index == DerivedMaskPointer::RECTANGLE_MASK)
		return GetMask()->CheckCollision(*DerivedMask.pRectangleMask);
	if(DerivedMask.index == DerivedMaskPointer::CIRCLE_MASK)
		return GetMask()->CheckCollision(*DerivedMask.pCircleMask);
	if(DerivedMask.index == DerivedMaskPointer::TRIANGLE_MASK)
		return GetMask()->CheckCollision(*DerivedMask.pTriangleMask);

	al_show_native_message_box(Display::GetDisplay(), "GameObject", "Error",
		"This part shouldn't be reached."
		"This error occured in bool GameObject::CheckCollision(GameObject *other)."
		"Please check all types of pointers in the DerivedMaskPointer struct.",
		0, ALLEGRO_MESSAGEBOX_ERROR);

	return false;
}

void GameObject::Collided(GameObject *other)
{
}