#pragma once
#include "pch.h"
#include "CSoundManager.h"

void CSoundManager::SoundSetUp()
{
	result = System_Create(&m_pSystem);
	result = m_pSystem->init(32, FMOD_INIT_NORMAL, 0);


	m_pSystem->createSound("content/sound/Title.mp3", FMOD_LOOP_NORMAL, nullptr, &m_pSound[(int)SOUND_TRACK::TITLE]);

	m_pSystem->createSound("content/sound/BGM1.wav", FMOD_LOOP_NORMAL, nullptr, &m_pSound[(int)SOUND_TRACK::BACKGROUND_SOUND]);

	m_pSystem->createSound("content/sound/END.wav", FMOD_LOOP_NORMAL, nullptr, &m_pSound[(int)SOUND_TRACK::ENDING_SOUND]);	

}

void CSoundManager::LoadMusic()
{
}

void CSoundManager::PlayMusic(SOUND_TRACK sound)
{
	StopMusic();
	 m_pSystem->playSound(m_pSound[(int)sound], 0, false, &m_pChannel);
	
}

void CSoundManager::PlayLoop(SOUND_TRACK sound)
{
	bool playing = false;
	m_pChannel->isPlaying(&playing);

	if (!playing)
	{
		m_pSystem->playSound(m_pSound[(int)sound], 0, false, &m_pChannel);
	}
}

void CSoundManager::StopMusic()
{
	m_pChannel->stop();
}

void CSoundManager::PauseMusic()
{
	m_pChannel->setPaused(true);
}

void CSoundManager::ReplayMusic()
{
	m_pChannel->setPaused(false);
}

void CSoundManager::ReleaseMusic()
{
	m_pSystem->release();
}

CSoundManager::CSoundManager()
{
	SoundSetUp();
}

CSoundManager::~CSoundManager()
{
	ReleaseMusic();
}