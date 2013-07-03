#ifndef _INCLUDED_OBJ_TEST2
#define _INCLUDED_OJB_TEST2

#include "GameObject.h"
#include "RectangleMask.h"
#include "Sprite.h"

class obj_Test2 : public GameObject
{
public:
  obj_Test2(void);
  ~obj_Test2(void);

  void Update();
  void Draw();

  Mask* GetMask()  {return &mask;}

private:
  RectangleMask mask;
  Sprite sprite;
};

#endif