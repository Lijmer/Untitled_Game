#ifndef _INCLUDE_TEXT_H
#define _INCLUDE_TEXT_H
#include <allegro5/allegro.h>
namespace Text
{
	enum FONT
	{
		NOKIA_FONT
	};

	void Init();
	void Clean();

	void DrawText(FONT font, ALLEGRO_COLOR color, float x, float y, int flags, char *text, ...);
	void DrawTextOutline(FONT font, ALLEGRO_COLOR innerColor, ALLEGRO_COLOR outerColor, float x, float y, float thickness, int flags, char const *text, ...);

}

#endif