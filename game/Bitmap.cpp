#include "Bitmap.h"
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include <map>
#include <string>

#include "Display.h"
using Display::GetDisplay;

namespace Bitmap
{
	//private variables
	std::map<unsigned int, ALLEGRO_BITMAP*> bitmap;
	std::vector<unsigned int> loadedBitmapID;

	//private functions forward-declerations
	const std::string& GetFilePath(unsigned int bitmapNum);
	bool IsBitmapLoaded(unsigned int bitmapNum);

	void InitBitmaps()
	{
		al_init_image_addon();
	}
	void DestroyBitmaps()
	{
		std::map<unsigned int, ALLEGRO_BITMAP*>::const_iterator iter;
		for(iter = bitmap.begin(); iter!=bitmap.end();)
			iter = bitmap.erase(iter);

		al_shutdown_image_addon();
	}

	void LoadBitmap(unsigned int bitmapNum)
	{
		if(IsBitmapLoaded(bitmapNum) || bitmapNum >= IMG_MAX)
			return;

		bitmap[bitmapNum] = al_load_bitmap(GetFilePath(bitmapNum).c_str());
		loadedBitmapID.push_back(bitmapNum);
	}
	void LoadBitmap(std::vector<unsigned int> &bitmapNum)
	{
		std::vector<unsigned int>::const_iterator iter;
		for(iter = bitmapNum.begin(); iter!=bitmapNum.end(); iter++)
		{
			if(IsBitmapLoaded(*iter) || (*iter)>=IMG_MAX)
				continue;
			bitmap[(*iter)] = al_load_bitmap(GetFilePath((*iter)).c_str());
			loadedBitmapID.push_back(*iter);
		}
	}

	const std::string& GetFilePath(unsigned int bitmapNum)
	{
		static std::string path = "";
		switch(bitmapNum)
		{
		case IMG_TEST:
			path = "img/test.png";
			break;
		default:
			al_show_native_message_box(GetDisplay(), "Bitmap", "Error",
				"Unknown imageID",0, ALLEGRO_MESSAGEBOX_ERROR);
			path = "img/error.png";
			break;
		}
		return path;
	}
	bool IsBitmapLoaded(unsigned int bitmapNum)
	{
		std::vector<unsigned int>::const_iterator iter;
		for(iter = loadedBitmapID.begin(); iter!=loadedBitmapID.end(); iter++)
		{
			if((*iter) == bitmapNum)
				return true;
		}

		return false;
	}

	ALLEGRO_BITMAP* GetBitmap(unsigned int bitmapNum)
	{
		if(IsBitmapLoaded(bitmapNum) && bitmapNum<IMG_MAX)
			return bitmap[bitmapNum];
		else
		{
			al_show_native_message_box(GetDisplay(), "Bitmap","Error",
				"Requested bitmap was not loaded", 0, ALLEGRO_MESSAGEBOX_ERROR);
			return 0;
		}
	}
}