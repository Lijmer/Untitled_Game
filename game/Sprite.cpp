#include "Sprite.h"
#include "Display.h"
#include "Exit.h"
#include <allegro5/allegro_native_dialog.h>
using namespace Bitmap;

Sprite::Sprite(void)
{}
Sprite::~Sprite(void)
{}

void Sprite::Init(unsigned int bitmapID, int offsetX, int offsetY, bool animated, int columnDirection, int rowDirection,
	int rowDelay, int columnDelay, int frameWidth, int frameHeight)
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

	Sprite::offsetX         = offsetX;
	Sprite::offsetY         = offsetY;
	Sprite::animated        = animated;
	Sprite::columnDirection = columnDirection;
	Sprite::columnDelay     = columnDelay;
	Sprite::rowDirection    = rowDirection;
	Sprite::rowDelay        = rowDelay;
	Sprite::frameWidth      = frameWidth;
	Sprite::frameHeight     = frameHeight;
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
	if(bitmap!=0)
	{
		//al_draw_bitmap_region(bitmap, frameWidth*row, frameHeight*column,
		//	frameWidth, frameHeight, x-offsetX, y-offsetY, 0);
		al_draw_bitmap(bitmap,x-offsetX,y-offsetY,0);
	}
	else
	{
		al_show_native_message_box(Display::GetDisplay(), "Sprite", "Error",
			"bitmap == 0 :(", 0, ALLEGRO_MESSAGEBOX_ERROR);
		Exit::Exit(1);
	}
}
