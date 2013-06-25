#ifndef _INCLUDE_MASK_H
#define _INCLUDE_MASK_H

class RectangleMask;
class CircleMask;
class TriangleMask;


struct DerivedMaskPointer
{
	union
	{
		RectangleMask *pRectangleMask;
		CircleMask    *pCircleMask;
		TriangleMask  *pTriangleMask;
	};
	enum index_t
	{
		RECTANGLE_MASK,
		CIRCLE_MASK,
		TRIANGLE_MASK
	}index;
	
};

class Mask
{
public:
	~Mask(void);

	virtual bool CheckCollision(const RectangleMask &other) const = 0;
	virtual bool CheckCollision(const CircleMask &other) const    = 0;
	virtual bool CheckCollision(const TriangleMask &other) const  = 0;
	//virtual bool CheckCollision(const Mask &other) const = 0;

protected:
	Mask(void);
	bool IsPInTriangle(float x1, float y1, float x2, float y2,
		float x3, float y3, float px, float py) const;
	bool IsPInCircle(float cx, float cy, float cr, float px, float py) const;
};

#endif //header guard