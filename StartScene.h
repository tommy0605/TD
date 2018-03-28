#pragma once
#include "GameNode.h"

class StartScene : public GameNode
{
private:
	Button * startBtn;
public:
	 virtual void Init();
	 virtual void Release();
	 virtual void Update();
	 virtual void Render(HDC hdc);

	 void ChangeScene();
};