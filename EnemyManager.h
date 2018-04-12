#pragma once

class EnemyManager
{
private:
	vector<Enemy*> enemyList;
	MapTool * mapt;
	int count;
public:
	EnemyManager();
	float dif;
	void Init(MapTool * map);
	void Render(HDC hdc);
	void Update();

	void Move(Enemy* enemy);

};