#pragma once
#include "GameObject.h"
#include "RectangleMask.h"
class obj_Test : public GameObject
{
public:
	obj_Test(void);
	~obj_Test(void);

	void Update();
	void Draw();
	void Destroy();

private:
	RectangleMask mask;
};

