#pragma once
#include "Mask.h"
class RectangleMask : public Mask
{
public:
	RectangleMask(void);
	~RectangleMask(void);

	void Init(float x=0, float y=0, int boundUp=0, int boundDown=0, int boundLeft=0, int boundRight=0);

	bool CheckCollision(const RectangleMask &other);
	bool CheckCollision(const CircleMask &other);
	bool CheckCollision(const TriangleMask &other);

	void SetX(float x)					{RectangleMask::x = x;}
	void SetY(float y)					{RectangleMask::y = y;}
	void SetBoundUp(int boundUp)		{RectangleMask::boundUp = boundUp;}	
	void SetBoundDown(int boundDown)	{RectangleMask::boundDown = boundDown;}
	void SetBoundLeft(int boundLeft)	{RectangleMask::boundLeft = boundLeft;}
	void SetBoundRight(int boundRight)	{RectangleMask::boundRight = boundRight;}

	float GetX() const			{return x;}
	float GetY() const			{return y;}
	int GetBoundUp() const		{return boundUp;}
	int GetBoundDown() const	{return boundDown;}
	int GetBoundLeft() const	{return boundLeft;}
	int GetBoundRight() const	{return boundRight;}

private:
	int boundUp;
	int boundDown;
	int boundLeft;
	int boundRight;

	float x;
	float y;
};

