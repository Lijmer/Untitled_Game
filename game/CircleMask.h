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

  bool CheckCollision(const RectangleMask &other) const;
  bool CheckCollision(const CircleMask &other)    const;
  bool CheckCollision(const TriangleMask &other)  const;
  bool CheckCollision(float x, float y)           const;

private:
  float x;
  float y;
  float radius;
};

