#pragma once



class BuildingManager
{
protected:
	map<string, Tower> towerList;
	
	vector<Tower*> usingTower;

public:
	void Init(string name, float hp, BUILDNAME bname);
	void Update();
	void Render(HDC hdc);

	void Attack();


	
};