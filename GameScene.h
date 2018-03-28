#pragma once
#include "GameNode.h"

class Tile;

class GameScene : public GameNode
{
private:
	vector<Tile*> totalList;
	vector<Tile*>::iterator it;
	
	//�����ִ� Ÿ���� ����
	vector<Tile*> openList;

	//����� ��θ� ���� ����
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