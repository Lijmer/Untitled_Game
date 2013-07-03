#include "Mask.h"
#include <math.h>

Mask::Mask(void)
{
}


Mask::~Mask(void)
{
}

bool Mask::IsPInTriangle(float x1, float y1, float x2, float y2,
  float x3, float y3, float px, float py) const
{
  //calculate the surface of triangle: ABC
  float A = abs((x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2))/2.0f);
  //calculate the surfaces of triangles: ABP, BCP en ACP
  float A1 = abs((px*(y2 - y3) + x2*(y3 - py) + x3*(py-y2))/2.0f);
  float A2 = abs((x1*(py - y3) + px*(y3 - y1) + x3*(y1-py))/2.0f);
  float A3 = abs((x1*(y2 - py) + x2*(py - y1) + px*(y1-y2))/2.0f);
  if(A == A1+A2+A3)
    return true;
  else
    return false;
}

bool Mask::IsPInCircle(float cx, float cy, float cr, float px, float py) const
{
  if((px-cx)*(px-cx) + (py-cy)*(py-cy) < cr*cr)
    return true;
  else
    return false;
}