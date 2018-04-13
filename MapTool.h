#pragma once

class MapTool :public GameNode
{
private:
	vector<Tile*> totalList;
	vector<Tile*>::iterator it;

	//갈수있는 타일의 벡터
	vector<Tile*> openList;

	//가까운 경로를 담은 벡터
	vector<Tile*> closeList;
	Tile* sampleTile[4];
	Tile* curTile;


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
	void TotalRender(HDC hdc);
	void SetSE();
	void AddOpenList();
	void SaveMap();
	void LoadMap();
	void PathFinder();
	void SetWall();
	RECT GetMouseRect();
	void SetTowerClosedMap(RECT rc);


	RECT GetEndTileRect() {
		if (endTile == NULL)
			return RECT{};
		return endTile->rc;
	}
	RECT GetStartTileRect() {
		if (startTile == NULL)
			return RECT{};
		return startTile->rc;
	}
	bool GetIsStart() { return isStart; }
	void SetIsStart(bool start) { isStart = start; }
	vector<Tile*> GetCloseList() { return closeList; }
};