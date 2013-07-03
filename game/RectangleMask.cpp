#include "RectangleMask.h"
#include "CircleMask.h"
#include "TriangleMask.h"
#include "globals.h"
RectangleMask::RectangleMask(void)
{
  boundUp=0;
  boundDown=0;
  boundLeft=0;
  boundRight=0;
  x=0;
  y=0;
}
RectangleMask::~RectangleMask(void)
{
}

void RectangleMask::Init(float x, float y, int boundUp, int boundDown, int boundLeft, int boundRight)
{
  RectangleMask::x          = x;
  RectangleMask::y          = y;
  RectangleMask::boundUp    = boundUp;
  RectangleMask::boundDown  = boundDown;
  RectangleMask::boundLeft  = boundLeft;
  RectangleMask::boundRight = boundRight;
}

bool RectangleMask::CheckCollision(const RectangleMask &other) const
{
 return(
    x + boundRight > other.GetX() - other.GetBoundLeft()  &&
    x - boundLeft  < other.GetX() + other.GetBoundRight() &&
    y + boundDown  > other.GetY() - other.GetBoundUp()    &&
    y - boundUp    < other.GetY() + other.GetBoundDown());

}
bool RectangleMask::CheckCollision(const CircleMask &other)    const
{
  /*points it checks:

  *---*---*
  |       |
  *   *   *
  |       |
  *---*---*

  */
  if(other.GetX() > x-boundLeft && other.GetX() < x+boundRight &&
    other.GetY() > y-boundDown && other.GetY() < y+boundUp)
    return true;

  if(IsPInCircle(other.GetX(), other.GetY(), other.GetRadius(), x-boundLeft, y-boundUp))
    return true;
  if(IsPInCircle(other.GetX(), other.GetY(), other.GetRadius(), x, y-boundUp))
    return true;
  if(IsPInCircle(other.GetX(), other.GetY(), other.GetRadius(), x+boundRight, y-boundUp))
    return true;
  if(IsPInCircle(other.GetX(), other.GetY(), other.GetRadius(), x-boundLeft, y))
    return true;
  if(IsPInCircle(other.GetX(), other.GetY(), other.GetRadius(), x, y))
    return true;
  if(IsPInCircle(other.GetX(), other.GetY(), other.GetRadius(), x+boundRight, y))
    return true;
  if(IsPInCircle(other.GetX(), other.GetY(), other.GetRadius(), x-boundLeft, y+boundDown))
    return true;
  if(IsPInCircle(other.GetX(), other.GetY(), other.GetRadius(), x, y+boundDown))
    return true;
  if(IsPInCircle(other.GetX(), other.GetY(), other.GetRadius(), x+boundRight, y+boundDown))
    return true;

  return false;
}
bool RectangleMask::CheckCollision(const TriangleMask &other)  const
{
  if(other.GetX1() > x-boundLeft && other.GetX1() < x+boundRight && other.GetY1() > y-boundUp && other.GetY1() < y+boundDown
    || other.GetX2() > x-boundLeft && other.GetX2() < x+boundRight && other.GetY2() > y-boundUp && other.GetY2() < y+boundDown
    || other.GetX3() > x-boundLeft && other.GetX3() < x+boundRight && other.GetY3() > y-boundUp && other.GetY3() < y+boundDown)
    return true;

  if(IsPInTriangle(other.GetX1(), other.GetY1(), other.GetX2(), other.GetY2(), other.GetX3(), other.GetY3(), x-boundLeft, y-boundUp))
    return true;
  if(IsPInTriangle(other.GetX1(), other.GetY1(), other.GetX2(), other.GetY2(), other.GetX3(), other.GetY3(), x+boundRight, y-boundUp))
    return true;
  if(IsPInTriangle(other.GetX1(), other.GetY1(), other.GetX2(), other.GetY2(), other.GetX3(), other.GetY3(), x+boundRight, y+boundDown))
    return true;
  if(IsPInTriangle(other.GetX1(), other.GetY1(), other.GetX2(), other.GetY2(), other.GetX3(), other.GetY3(), x-boundLeft, y+boundDown))
    return true;

  return false;
}
bool RectangleMask::CheckCollision(float x, float y)           const
{
  return(
    x >= RectangleMask::x - boundLeft  &&
    x < RectangleMask::x + boundRight &&
    y >= RectangleMask::y - boundUp    &&
    y < RectangleMask::y + boundDown);
}
