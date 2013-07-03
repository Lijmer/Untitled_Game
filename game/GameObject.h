#ifndef _INCLUDE_GAMEOBJECT_H
#define _INCLUDE_GAMEOBJECT_H

#include "globals.h"
#include "Mask.h"
#include "CircleMask.h"
#include "RectangleMask.h"
#include "TriangleMask.h"
#include "objManager.h"
class GameObject
{
public:
  ~GameObject(void);

  virtual void  Init(float x, float y, float velX, float velY);
  virtual void  Update();
  virtual void  Draw();
  virtual void  Destroy();
  virtual void  Collided(GameObject *other);
  virtual Mask* GetMask() {return 0;}

  bool  CheckCollision(GameObject *other);
  bool  CheckCollision(Mask &other);
  bool  CheckCollision(float x, float y);

  bool     GetCollidable() const      {return collidable;}
  int      GetDepth()      const      {return depth;}
  float    GetX()          const      {return x;}
  float    GetY()          const      {return y;}
  objectID GetID()         const      {return ID;}

  void SetX(float x)                  {GameObject::x = x;}
  void SetY(float y)                  {GameObject::y = y;}
  void SetVelX(float velX)            {GameObject::velX = velX;}
  void SetVelY(float velY)            {GameObject::velY = velY;}
  void SetCollidable(bool collidable) {GameObject::collidable = collidable;}
  void SetDepth(int depth)            {GameObject::depth = depth;}

protected:
  GameObject(void);
  float x;
  float y;
  float velX;
  float velY;
private:
  objectID ID;
  bool collidable;
  int depth;
};

#endif