#include "CircleMask.h"
#include "TriangleMask.h"
#include "RectangleMask.h"

CircleMask::CircleMask(void)
{
}
CircleMask::~CircleMask(void)
{
}

bool CircleMask::CheckCollision(const RectangleMask &other) const
{
  if(x > other.GetX()-other.GetBoundLeft() && x < other.GetX()+other.GetBoundRight() &&
    y > other.GetY()-other.GetBoundDown() && y < other.GetY()+other.GetBoundUp())
    return true;

  if(IsPInCircle(x, y, radius, other.GetX()-other.GetBoundLeft(), other.GetY()-other.GetBoundUp()))
    return true;
  if(IsPInCircle(x, y, radius, other.GetX(), other.GetY()-other.GetBoundUp()))
    return true;
  if(IsPInCircle(x, y, radius, other.GetX()+other.GetBoundRight(), other.GetY()-other.GetBoundUp()))
    return true;
  if(IsPInCircle(x, y, radius, other.GetX()-other.GetBoundLeft(), other.GetY()))
    return true;
  if(IsPInCircle(x, y, radius, other.GetX(), other.GetY()))
    return true;
  if(IsPInCircle(x, y, radius, other.GetX()+other.GetBoundRight(), other.GetY()))
    return true;
  if(IsPInCircle(x, y, radius, other.GetX()-other.GetBoundLeft(), other.GetY()+other.GetBoundDown()))
    return true;
  if(IsPInCircle(x, y, radius, other.GetX(), other.GetY()+other.GetBoundDown()))
    return true;
  if(IsPInCircle(x, y, radius, other.GetX()+other.GetBoundRight(), other.GetY()+other.GetBoundDown()))
    return true;

  return false;
}
bool CircleMask::CheckCollision(const CircleMask &other)    const
{
  return ((x-other.x)*(x-other.x) + (y-other.y)*(y-other.y) > (radius+other.radius)*(radius+other.radius));
}
bool CircleMask::CheckCollision(const TriangleMask &other)  const
{
  return false;
}
bool CircleMask::CheckCollision(float x, float y)           const
{
  return IsPInCircle(CircleMask::x, CircleMask::y, radius, x, y);
}