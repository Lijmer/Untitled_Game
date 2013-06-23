#pragma once
#include "Mask.h"
class CircleMask : public Mask
{
public:
	CircleMask(void);
	~CircleMask(void);

	float GetX() const		{return x;}
	float GetY() const		{return y;}
	float GetRadius() const	{return radius;}

	bool CheckCollision(const RectangleMask &other);
	bool CheckCollision(const CircleMask &other);
	bool CheckCollision(const TriangleMask &other);

private:
	float x;
	float y;
	float radius;
};

