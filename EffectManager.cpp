#include "stdafx.h"

void EffectManager::Release()
{
	vEffect::iterator vIter;

	for (it = totalEffect.begin(); it != totalEffect.end(); it++)
	{
		for (vIter = it->second.begin(); vIter != it->second.end();)
		{
			(*vIter)->Release();
			delete *vIter;
			vIter = it->second.erase(vIter);
		}
	}
}

void EffectManager::Update()
{
	for (it = totalEffect.begin(); it != totalEffect.end(); it++)
	{
		for (int i = 0; i < it->second.size(); i++)
		{
			it->second[i]->Update();
		}
	}
}

void EffectManager::Render(HDC hdc)
{
	for (it = totalEffect.begin(); it != totalEffect.end(); it++)
	{
		for (int i = 0; i < it->second.size(); i++)
		{
			it->second[i]->Render(hdc);
		}
	}
}

void EffectManager::AddEffect(string effectName, const TCHAR * imageName, int imageWidth, int imageHeight, int frameX, int frameY, int fps, int buffer, COLORREF color)
{
	Image* img;

	img = IMAGEMANAGER->AddImage(effectName, imageName,
		imageWidth, imageHeight, frameX, frameY, true, color);

	vEffect effect;

	for (int i = 0; i < buffer; i++)
	{
		effect.push_back(new Effect);
		effect[i]->Init(img, fps);
	}

	totalEffect.insert(pair<string, vEffect>(effectName, effect));
}

void EffectManager::Play(string effectName, int x, int y)
{
	it = totalEffect.find(effectName);

	if (it != totalEffect.end())
	{
		for (int i = 0; i < it->second.size(); i++)
		{
			if (it->second[i]->GetIsRun())
				continue;
			it->second[i]->StartEffect(POINT{ x, y });
			return;
		}
	}
}

void EffectManager::Play(string effectName, POINT pos)
{
	it = totalEffect.find(effectName);

	if (it != totalEffect.end())
	{
		for (int i = 0; i < it->second.size(); i++)
		{
			if (it->second[i]->GetIsRun())
				continue;
			it->second[i]->StartEffect(pos);
			return;
		}
	}
}
