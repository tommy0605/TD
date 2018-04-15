#pragma once

class EnemyManager
{
private:
	vector<Enemy*> enemyList;
	MapTool * mapt;
	vector<Tile*> closeList;
	int count;
public:
	EnemyManager();
	float dif;
	void Init(MapTool * map);
	void Render(HDC hdc);
	void Update();

	void Move();
	inline vector<Enemy*> GetEnemyLsit() { return enemyList; }
};