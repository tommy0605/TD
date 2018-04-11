#pragma once
#include "GameNode.h"

class Tile;

class GameScene : public GameNode
{
private:
	MapTool * map;
	BuildingManager* bm;
	RECT mouseRC;
	Tower* curTower;
	Tower ccTower;
	POINT endPos;
	POINT startPos;

	bool isPause;
public:
	virtual void Init();
	virtual void Update();
	virtual void Render(HDC hdc);
	virtual void Release();
	
	void SetCurrTower();

	void SetMap(MapTool* maap) { map = maap; }
};