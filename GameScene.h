#pragma once
#include "GameNode.h"

class Tile;

class GameScene : public GameNode
{
private:
	vector<Tile*> totalList;
	vector<Tile*>::iterator it;
	
	//갈수있는 타일의 벡터
	vector<Tile*> openList;

	//가까운 경로를 담은 벡터
	vector<Tile*> closeList;

	Tile* startTile;
	Tile* endTile;

	Tile* currentTile;

	int count;
	bool isStart;
public:
	virtual void Init();
	virtual void Update();
	virtual void Render(HDC hdc);
	virtual void Release();

	void SetTile();
	void AddOpenList();
	void PathFinder();
	void SetWall();
};