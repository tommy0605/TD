#pragma once



class BuildingManager
{
protected:
	map<string, Tower> towerList;
	
	vector<Tower*> usingTower;

public:
	void Init();
	void Update();
	void Render(HDC hdc);

	Tower* FindTower(string key);
	Tower* SetCurrTower();
	void Attack();


	
};