#pragma once
class RectangleMask;
class CircleMask;
class TriangleMask;
class Mask
{
public:
	Mask(void);
	~Mask(void);

	virtual bool CheckCollision(const RectangleMask &other) = 0;
	virtual bool CheckCollision(const CircleMask &other)    = 0;
	virtual bool CheckCollision(const TriangleMask &other)  = 0;

protected:
	bool IsPInTriangle(float x1, float y1, float x2, float y2,
		float x3, float y3, float px, float py);
	bool IsPInCircle(float cx, float cy, float cr, float px, float py);
	/*
	enum type
	{
		RECTANGLE,
		TRIANGE,
		CIRCLE
	};
	
protected:
	void SetType(int type)	{Mask::type = type;}
	int GetType()			{return type;}

private:
	int type
	*/
};

