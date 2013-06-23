#include "level.h"
#include <allegro5/allegro_native_dialog.h>
#include <string>
#include <vector>
#include <fstream>
#include "Display.h"

using Display::GetDisplay;

namespace Level
{
	int currentLevel = 0;

	std::string& GetFilePathMap(unsigned int levelID);
	std::vector<std::string>& LoadMap(unsigned int levelID);

	void LoadLevel(unsigned int levelID)
	{
		std::vector<std::string> map = LoadMap(levelID);
		std::vector<std::string>::const_iterator iter;
		std::string::const_iterator strIter;

		for(iter = map.begin(); iter != map.end(); iter++)
		{
			for(strIter = (*iter).begin(); strIter != (*iter).end(); strIter++)
			{
				
			}
		}
	}
	void SaveLevel()
	{
	}
	int GetCurrentLevel()
	{
		return currentLevel;
	}

	std::string& GetFilePathMap(unsigned int levelID)
	{
		static std::string filePath = "";
		switch(levelID)
		{
		case LVL_TEST:
			filePath = "level/test/map";
			break;
		default:
			al_show_native_message_box(GetDisplay(), "Level", "Error",
				"Unknown levelID", 0, ALLEGRO_MESSAGEBOX_ERROR);
			filePath = "";
			break;
		}		
		return filePath;
	}
	std::vector<std::string>& LoadMap(unsigned int levelID)
	{
		static std::vector<std::string> map;
		static unsigned int currentLoadedMap = LVL_MAX;
		if(currentLoadedMap == levelID)
			return map;

		currentLoadedMap = levelID;
		map.clear();

		std::ifstream file;
		file.open(GetFilePathMap(levelID));
		if(!file.is_open())
		{
			al_show_native_message_box(GetDisplay(), "Level", "Error",
				"Couldn't open map file", 0, ALLEGRO_MESSAGEBOX_ERROR);
			return map;
		}
		std::string temp = "";
		while(std::getline(file, temp))
		{
			map.push_back(temp);
			temp="";
		}
		file.close();

		if(file.is_open())
		{
			al_show_native_message_box(GetDisplay(), "Level", "Error",
				"Couldn't close map file", 0, ALLEGRO_MESSAGEBOX_ERROR);
		}

		return map;
	}
}