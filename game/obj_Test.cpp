#include "obj_Test.h"
#include "Keyboard.h"
#include <allegro5/allegro_primitives.h>

using namespace Keyboard;

obj_Test::obj_Test(void)
{
	mask.Init(0,0,10,10,10,10);
}


obj_Test::~obj_Test(void)
{
}

void obj_Test::Update()
{
	if(GetKey(ALLEGRO_KEY_W))
		y-=1;
	if(GetKey(ALLEGRO_KEY_S))
		y+=1;
	if(GetKey(ALLEGRO_KEY_A))
		x-=1;
	if(GetKey(ALLEGRO_KEY_D))
		x+=1;


}

void obj_Test::Draw()
{
	al_draw_filled_rectangle(x-10, y-10, x+10, y+10, al_map_rgb(255,255,255));
}

void obj_Test::Destroy()
{

}