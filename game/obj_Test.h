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
	void Destroy();
	void Collided(GameObject *other);

	const Mask*               GetMask()        {return &mask;}
	const DerivedMaskPointer* GetDerivedMask() {return &derivedMaskPointer;}

private:
	Sprite sprite;
	RectangleMask mask;
	DerivedMaskPointer derivedMaskPointer;
};

#endif