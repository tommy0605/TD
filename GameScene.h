#pragma once
#include "GameNode.h"

class Tile;

class GameScene : public GameNode
{
private:
	MapTool * map;

	bool isPause;
public:
	virtual void Init();
	virtual void Update();
	virtual void Render(HDC hdc);
	virtual void Release();

};