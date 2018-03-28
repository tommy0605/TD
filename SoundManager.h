#pragma once
#include "SingletonBase.h"

#include "inc/fmod.hpp"
#pragma comment(lib, "lib/fmodex_vc.lib")

using namespace FMOD;

#define TOTALSOUNDBUFFER 15

struct SoundInfo
{
	Sound* sound;
	Channel* channel;

	SoundInfo()
	{
		sound = NULL;
		channel = NULL;
	}
};

class SoundManager : public SingletonBase<SoundManager>
{
private:
	System * _system;
	
	map<string, SoundInfo*> totalSound;
	map<string, SoundInfo*>::iterator it;
public:
	void Init();
	void AddSound(string keyName, string soundName, bool bgm, bool loop);

	void Play(string keyName, float volume);
	void Stop(string keyName);
	void Pause(string keyName);
	void Resume(string keyName);

	bool isPlaySound(string keyName);
	bool isPauseSound(string keyName);
};