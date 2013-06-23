#pragma once
#include <allegro5/allegro.h>
#include "Bitmap.h"

class Sprite
{
public:
	Sprite(unsigned int bitmapID, bool animated = false, int columnDirection = 0, int rowDirection = 0, int rowDelay = 0,
		int columnDelay = 0, int frameWidth = 0, int frameHeight = 0, int offsetX = 0, int offsetY = 0);
	~Sprite(void);
	
	void Update();
	void Draw(float x, float y);

	void SetRow(int row)							{Sprite::row             = row;}
	void SetColumn(int column)						{Sprite::column          = column;}
	void SetRowDirection(int rowDirection)			{Sprite::rowDirection    = rowDirection;}
	void SetColumnDirection(int columnDirection)	{Sprite::columnDirection = columnDirection;}
	void SetRowDelay(int rowDelay)					{Sprite::rowDelay        = rowDelay;}
	void SetColumnDelay(int columnDelay)			{Sprite::columnDelay     = columnDelay;}
	
	
private:
	ALLEGRO_BITMAP* bitmap;

	int bitmapWidth;
	int bitmapHeight;
	
	int offsetX;
	int offsetY;

	bool animated;
	
	int column;
	int row;
	int columnDirection;
	int rowDirection;
	int columnDelay;
	int rowDelay;
	int columnCount;
	int rowCount;
	int maxColumn;
	int maxRow;
	int frameWidth;
	int frameHeight;

	float x;
	float y;
};
