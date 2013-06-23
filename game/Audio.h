#ifndef AUDIO_H
#define AUDIO_H

#include <vector>

namespace Audio
{
	enum sampleIDs
	{
		SND_TEST,
		SND_MAX
	};

	void InitAudio();
	void DestroyAudio();

	void LoadSample(unsigned int sampleID);
	void LoadSample(std::vector<unsigned int> &sampleID);

	bool PlaySample(unsigned int sampleID);
}
#endif