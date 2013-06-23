#include "Audio.h"
#include "globals.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_native_dialog.h>
#include <map>
#include "Display.h"

using Display::GetDisplay;

namespace Audio
{
	std::map<unsigned int, ALLEGRO_SAMPLE*> samples;
	std::vector<unsigned> loadedSamples;
	
	std::string& GetFilePath(unsigned int sampleID);
	bool IsSampleLoaded(unsigned int sampleID);

	void InitAudio()
	{
		al_install_audio();
		al_init_acodec_addon();
		al_reserve_samples(1);	//todo reserve correct amount of samples
	}
	void DestroyAudio()
	{
		std::map<unsigned int, ALLEGRO_SAMPLE*>::iterator iter;
		for(iter = samples.begin(); iter!=samples.end();)
		{
			iter = samples.erase(iter);
		}
		al_uninstall_audio();
	}
	void LoadSample(unsigned int sampleID)
	{
		if(IsSampleLoaded(sampleID) || sampleID>=SND_MAX)
			return;

		samples[sampleID] = al_load_sample(GetFilePath(sampleID).c_str());
		loadedSamples.push_back(sampleID);
	}
	void LoadSample(std::vector<unsigned int> &sampleID)
	{
		std::vector<unsigned int>::const_iterator iter;
		for(iter = sampleID.begin(); iter!=sampleID.end(); iter++)
		{
			if(IsSampleLoaded(*iter) || (*iter)>=SND_MAX)
				continue;
			samples[(*iter)] = al_load_sample(GetFilePath(*iter).c_str());
			loadedSamples.push_back(*iter);
		}
	}
	bool PlaySample(unsigned int sampleID)
	{
		if(sampleID >= SND_MAX || !IsSampleLoaded(sampleID))
		{
			al_show_native_message_box(GetDisplay(), "Audio", "Error",
				"Unknown sample ID or sample isn't loaded", 0, ALLEGRO_MESSAGEBOX_ERROR);
			return false;
		}
		al_play_sample(samples[sampleID],1,0,1,ALLEGRO_PLAYMODE_ONCE, 0);
		return true;
	}

	std::string& GetFilePath(unsigned sampleID)
	{
		static std::string filePath;
		switch(sampleID)
		{
		case SND_TEST:
			filePath = "sound/test.wav";
			break;
		default:
			al_show_native_message_box(GetDisplay(), "Audio", "Error",
				"Unknown Sample ID", 0, ALLEGRO_MESSAGEBOX_ERROR);
			filePath = "";
			break;
		}
		return filePath;
	}
	bool IsSampleLoaded(unsigned sampleID)
	{
		std::vector<unsigned int>::const_iterator iter;
		for(iter = loadedSamples.begin(); iter!=loadedSamples.end(); iter++)
		{
			if((*iter) == sampleID)
				return true;
		}
		return false;
	}
}