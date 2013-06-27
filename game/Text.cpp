#include "Text.h"
#include "globals.h"
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "Display.h"
#include <stdarg.h>
#include <map>
#include <sstream>
namespace Text
{
	std::map<FONT, ALLEGRO_FONT*> fonts;
	inline ALLEGRO_FONT* GetFont(FONT font)
	{
		if(fonts[font]!=0)
			return fonts[font];
		else
		{
			al_show_native_message_box(Display::GetDisplay(), "Text", "Error", "font == 0", 0, ALLEGRO_MESSAGEBOX_ERROR);
			return 0;
		}
	}

	void Init()
	{
		al_init_font_addon();
		al_init_ttf_addon();

		fonts[NOKIA_FONT] = al_load_font("fonts/nokiafc22.ttf", 18, 0);
		if(!fonts[NOKIA_FONT])
		{
			al_show_native_message_box(Display::GetDisplay(), "Text", "Error", "Failed to load font", 0, ALLEGRO_MESSAGEBOX_ERROR);
		}
	}
	void Clean()
	{
		std::map<FONT, ALLEGRO_FONT*>::iterator iter;
		for(iter = fonts.begin(); iter!=fonts.end();)
		{
			al_destroy_font((*iter).second);
			iter = fonts.erase(iter);
		}

		al_shutdown_font_addon();
		al_shutdown_ttf_addon();
	}
	
	void DrawText(FONT font, ALLEGRO_COLOR color, float x, float y, int flags, char *text, ...)
	{
		char buffer[256];
		va_list args;
		va_start(args, text);
		vsnprintf_s(buffer, 255, text, args);

		al_draw_textf(GetFont(font), color, x, y, flags, "%s", buffer);

		va_end(args);
	}
	void DrawTextOutline(FONT font, ALLEGRO_COLOR innerColor, ALLEGRO_COLOR outerColor, float x, float y, float thickness, int flags, char const *text, ...)
	{
		char buffer[256];
		va_list args;
		va_start(args, text);
		vsnprintf_s(buffer, 255, text, args);

		al_draw_textf(GetFont(font), outerColor, x-thickness, y-thickness, flags, "%s", buffer);
		al_draw_textf(GetFont(font), outerColor, x-thickness, y,           flags, "%s", buffer);
		al_draw_textf(GetFont(font), outerColor, x-thickness, y+thickness, flags, "%s", buffer);
		al_draw_textf(GetFont(font), outerColor, x,           y-thickness, flags, "%s", buffer);
		al_draw_textf(GetFont(font), outerColor, x,           y,           flags, "%s", buffer);
		al_draw_textf(GetFont(font), outerColor, x,           y+thickness, flags, "%s", buffer);
		al_draw_textf(GetFont(font), outerColor, x+thickness, y-thickness, flags, "%s", buffer);
		al_draw_textf(GetFont(font), outerColor, x+thickness, y,           flags, "%s", buffer);
		al_draw_textf(GetFont(font), outerColor, x+thickness, y+thickness, flags, "%s", buffer);
		al_draw_textf(GetFont(font), innerColor, x,           y,           flags, "%s", buffer);

		va_end(args);
	}
}