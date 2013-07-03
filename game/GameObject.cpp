#include "GameObject.h"
#include <allegro5/allegro_native_dialog.h>
#include "Display.h"

GameObject::GameObject(void)
{
  x=0;
  y=0;
  velX=0;
  velY=0;

  ID = UNDEFINED;
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
  if(RectangleMask* mask = dynamic_cast<RectangleMask*>(other->GetMask()))
    return GetMask()->CheckCollision(*mask);

  else if(TriangleMask* mask = dynamic_cast<TriangleMask*>(other->GetMask()))
    return GetMask()->CheckCollision(*mask);

  else if(CircleMask* mask = dynamic_cast<CircleMask*>(other->GetMask()))
    return GetMask()->CheckCollision(*mask);


  al_show_native_message_box(Display::GetDisplay(), "GameObject", "Error",
    "This part shouldn't be reached."
    "This error occured in bool GameObject::CheckCollision(GameObject *other)."
    "Please check all types of pointers in the DerivedMaskPointer struct.",
    0, ALLEGRO_MESSAGEBOX_ERROR);

  return false;
}
bool GameObject::CheckCollision(Mask &other)
{
  if(RectangleMask* mask = dynamic_cast<RectangleMask*>(&other))
    return GetMask()->CheckCollision(*mask);

  else if(TriangleMask* mask = dynamic_cast<TriangleMask*>(&other))
    return GetMask()->CheckCollision(*mask);

  else if(CircleMask* mask = dynamic_cast<CircleMask*>(&other))
    return GetMask()->CheckCollision(*mask);
}
bool GameObject::CheckCollision(float x, float y)
{
  return GetMask()->CheckCollision(x,y);
}

void GameObject::Collided(GameObject *other)
{
}