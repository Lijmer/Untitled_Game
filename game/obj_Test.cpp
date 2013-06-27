#include "obj_Test.h"
#include "Keyboard.h"
#include <allegro5/allegro_primitives.h>

obj_Test::obj_Test(void)
{
	sprite.Init(Bitmap::IMG_TEST, 16,16);
	mask.Init(0,0,16,16,16,16);
	derivedMaskPointer.pRectangleMask = &mask;
	derivedMaskPointer.index = DerivedMaskPointer::RECTANGLE_MASK;
	SetDepth(0);
}

obj_Test::~obj_Test(void)
{
}

void obj_Test::Update()
{
	if(Keyboard::GetKey(ALLEGRO_KEY_W))
		y-=1;
	if(Keyboard::GetKey(ALLEGRO_KEY_S))
		y+=1;
	if(Keyboard::GetKey(ALLEGRO_KEY_A))
		x-=1;
	if(Keyboard::GetKey(ALLEGRO_KEY_D))
		x+=1;
	sprite.Update();
}

void obj_Test::Draw()
{
	sprite.Draw(x,y);
}

void obj_Test::Destroy()
{

}

void obj_Test::Collided(GameObject *other)
{
}