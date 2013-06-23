#include "Sprite.h"

using namespace Bitmap;

Sprite::Sprite(unsigned int bitmapID, bool animated, int columnDirection, int rowDirection,
	int rowDelay, int columnDelay, int frameWidth, int frameHeight, int offsetX, int offsetY)
{
	bitmap = GetBitmap(bitmapID);

	if(bitmap)
	{
		bitmapWidth  = al_get_bitmap_width(bitmap);
		bitmapHeight = al_get_bitmap_height(bitmap);
	}
	else
	{
		bitmapWidth     = 0;
		bitmapHeight    = 0;
	}

	Sprite::animated        = animated;
	Sprite::columnDirection = columnDirection;
	Sprite::columnDelay     = columnDelay;
	Sprite::rowDirection    = rowDirection;
	Sprite::rowDelay        = rowDelay;
	Sprite::frameWidth      = frameWidth;
	Sprite::frameHeight     = frameHeight;
	Sprite::offsetX         = offsetX;
	Sprite::offsetY         = offsetY;
	x                       = 0;
	y                       = 0;
	column                  = 0;
	row                     = 0;

	if(frameWidth!=0)
		maxRow = (int)bitmapWidth/(int)frameWidth;
	else
		maxRow = 0;

	if(frameHeight!=0)
		maxColumn = (int)bitmapHeight/(int)frameHeight;
	else
		maxColumn = 0;
}


Sprite::~Sprite(void)
{}

void Sprite::Update()
{
	if(!animated)
		return;
	if(++columnCount > columnDelay)
	{
		columnCount  = 0;
		column      += columnDirection;

		while(column > maxColumn)
			column -= maxColumn;
	}

	if(++rowCount > rowDelay)
	{
		rowCount  = 0;
		row      += columnDirection;

		while(row > maxRow)
			row -= maxRow;
	}
}

void Sprite::Draw(float x, float y)
{
	al_draw_bitmap_region(bitmap, frameWidth*row, frameHeight*column,
		frameWidth, frameHeight, x-offsetX, y-offsetY, 0);
}