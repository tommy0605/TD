#pragma once
#include "GameNode.h"

#include "inc/fmod.hpp"

#pragma comment (lib, "lib/fmodex_vc.lib")

using namespace FMOD;

class MainGame : public GameNode
{
private:	

public:
	virtual void Init();
	virtual void Update();
	virtual void Render(HDC hdc);
	virtual void Release();
};