#include "TriangleMask.h"
#include "RectangleMask.h"
#include "CircleMask.h"

TriangleMask::TriangleMask(void)
{
}


TriangleMask::~TriangleMask(void)
{
}

bool TriangleMask::CheckCollision(const RectangleMask &other) const
{
	if((x1 > other.GetX()-other.GetBoundLeft() && x1 < other.GetX()+other.GetBoundRight()
		&& y1 > other.GetY()-other.GetBoundUp() && y1 < other.GetY()+other.GetBoundDown())
		||
		(x2 > other.GetX()-other.GetBoundLeft() && x2 < other.GetX()+other.GetBoundRight()
		&& y2 > other.GetY()-other.GetBoundUp() && y2 < other.GetY()+other.GetBoundDown())
		||
		(x3 > other.GetX()-other.GetBoundLeft() && x3 < other.GetX()+other.GetBoundRight() 
		&& y3 > other.GetY()-other.GetBoundUp() && y3 < other.GetY()+other.GetBoundDown()))
		return true;

	if(IsPInTriangle(x1, y1, x2, y2, x3, y3, other.GetX()-other.GetBoundLeft(), other.GetY()-other.GetBoundUp()))
		return true;
	if(IsPInTriangle(x1, y1, x2, y2, x3, y3, other.GetX()+other.GetBoundRight(), other.GetY()-other.GetBoundUp()))
		return true;
	if(IsPInTriangle(x1, y1, x2, y2, x3, y3, other.GetX()+other.GetBoundRight(), other.GetY()+other.GetBoundDown()))
		return true;
	if(IsPInTriangle(x1, y1, x2, y2, x3, y3, other.GetX()-other.GetBoundLeft(), other.GetY()+other.GetBoundDown()))
		return true;

	return false;
}
bool TriangleMask::CheckCollision(const CircleMask &other) const
{
	return false;
}
bool TriangleMask::CheckCollision(const TriangleMask &other) const
{
	if(IsPInTriangle(x1,y1,x2,y2,x3,y3, other.GetX1(), other.GetY1()))
		return true;
	if(IsPInTriangle(x1,y1,x2,y2,x3,y3, other.GetX2(), other.GetY2()))
		return true;
	if(IsPInTriangle(x1,y1,x2,y2,x3,y3, other.GetX3(), other.GetY3()))
		return true;

	if(IsPInTriangle(other.GetX1(), other.GetY1(), other.GetX2(), other.GetY2(), other.GetX3(), other.GetY3(), x1, y1))
		return true;
	if(IsPInTriangle(other.GetX1(), other.GetY1(), other.GetX2(), other.GetY2(), other.GetX3(), other.GetY3(), x2, y2))
		return true;
	if(IsPInTriangle(other.GetX1(), other.GetY1(), other.GetX2(), other.GetY2(), other.GetX3(), other.GetY3(), x3, y3))
		return true;
	return false;
}