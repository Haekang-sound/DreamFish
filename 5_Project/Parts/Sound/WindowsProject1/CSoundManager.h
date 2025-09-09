#pragma once
#include "pch.h"

using namespace FMOD;

class CSoundManager
{
	SINGLE(CSoundManager);

public:
	void PlayMusic(SOUND_TRACK sound);
	void PlayLoop(SOUND_TRACK sound);
	
	
	void StopMusic();
	void PauseMusic();
	void ReplayMusic();
	void ReleaseMusic();
	void SoundSetUp();
	void LoadMusic();

private:
	System* m_pSystem;

	Sound* m_pSound[(int)SOUND_TRACK::END];
	Channel* m_pChannel;

	FMOD_RESULT result;
};

