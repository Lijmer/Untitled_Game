#ifndef _INCLUDE_GAMEOBJECT_H
#define _INCLUDE_GAMEOBJECT_H

#include "globals.h"
#include "Mask.h"
#include "CircleMask.h"
#include "RectangleMask.h"
#include "TriangleMask.h"
class GameObject
{
public:
	~GameObject(void);

	virtual void  Init(float x, float y, float velX, float velY);
	virtual void  Update();
	virtual void  Draw();
	virtual void  Destroy();
	        bool  CheckCollision(GameObject *other);
	virtual void  Collided(GameObject *other);
	virtual const Mask*               GetMask()
	{return 0;}
	virtual const DerivedMaskPointer* GetDerivedMask()
	{return 0;}

	bool GetCollidable()     {return collidable;}
	int GetDepth()           {return depth;}

	void SetDepth(int depth) {GameObject::depth = depth;}

protected:
	GameObject(void);
	float x;
	float y;
	float velX;
	float velY;
private:
	int ID;
	bool collidable;
	int depth;
};

#endif