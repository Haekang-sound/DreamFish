#pragma once
#include "pch.h"
#include "CSoundManager.h"

void CSoundManager::SoundSetUp()
{
	result = System_Create(&m_pSystem);
	result = m_pSystem->init(1, FMOD_INIT_NORMAL, 0);

	m_pSystem->createSound("content/sound/Title.mp3", FMOD_LOOP_NORMAL, 0, &m_pSound[(int)SOUND_TRACK::BACKGROUND_SOUND]);
	assert(m_pSystem);
	//m_pSystem->createSound("content/sound/MrBlueSky.mp3", FMOD_LOOP_NORMAL, 0, &m_pSound[(int)SOUND_TRACK::BACKGROUND_SOUND]);
	//assert(m_pSystem); 동재님이 좋아하시는 노래 원픽 

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