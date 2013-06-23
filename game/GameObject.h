#pragma once
#include "globals.h"
#include "Mask.h"
class GameObject
{
public:
	GameObject(void);
	~GameObject(void);

	virtual void Init(float x, float y, float velX, float velY);
	virtual void Update();
	virtual void Draw();
	virtual void Destroy();

	virtual Mask* GetMask()	{return 0;}
protected:
	float x;
	float y;
	float velX;
	float velY;
private:
	int ID;
	int collidable;
	int depth;
};
