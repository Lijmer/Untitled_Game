#ifndef _INCLUDE_OBJ_TEST_H
#define _INCLUDE_OBJ_TEST_H

#include "GameObject.h"
#include "RectangleMask.h"
#include "Sprite.h"

class obj_Test : public GameObject
{
public:
  obj_Test(void);
  ~obj_Test(void);

  void Update();
  void Draw();

  Mask*               GetMask()        {return &mask;}

private:
  Sprite sprite;
  RectangleMask mask;
};

#endif