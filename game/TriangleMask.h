#pragma once
#include "Mask.h"
class TriangleMask : public Mask
{
public:
	TriangleMask(void);
	~TriangleMask(void);

	bool CheckCollision(const RectangleMask &other) const;
	bool CheckCollision(const CircleMask &other) const;
	bool CheckCollision(const TriangleMask &other) const;

	float GetX1() const	{return x1;}
	float GetY1() const	{return y1;}
	float GetX2() const	{return x2;}
	float GetY2() const	{return y2;}
	float GetX3() const	{return x3;}
	float GetY3() const	{return y3;}

private:
	float x1;
	float y1;
	float x2;
	float y2;
	float x3;
	float y3;
};

