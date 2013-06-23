#include "GameObject.h"


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