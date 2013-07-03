#include "obj_Test2.h"


obj_Test2::obj_Test2(void)
{
  SetDepth(-1);
  sprite.Init(Bitmap::IMG_TEST2);
}


obj_Test2::~obj_Test2(void)
{
}

void obj_Test2::Update()
{

}

void obj_Test2::Draw()
{
 sprite.Draw(x,y); 
}