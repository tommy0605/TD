#pragma once
#include "GameNode.h"

class Tile;

class GameScene : public GameNode
{
private:
	MapTool * map;
	BuildingManager* bm;
	EnemyManager* em;
	float dif;
	RECT mouseRC;
	RECT endRect;
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
	
	POINT AttackLock(POINT pos, int radius);

	void SetMap(MapTool* maap) { map = maap; }
};