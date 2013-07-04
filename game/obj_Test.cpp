#include "obj_Test.h"
#include "Keyboard.h"
#include <allegro5/allegro_primitives.h>

obj_Test::obj_Test(void)
{
  sprite.Init(Bitmap::IMG_TEST, 0,0);
  mask.Init(0,0,0,32,0,32);
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
  mask.SetX(x);
  mask.SetY(y);
}
void obj_Test::Draw()
{
  sprite.Draw(x,y);
  //al_draw_filled_rectangle(x, y, x+32, y+32, al_map_rgba(255,0,0,100));
}
