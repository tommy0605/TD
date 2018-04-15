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
	void UsingTowerRender(HDC hdc);

	Tower* FindTower(string key);
	Tower* SetCurrTower();
	void SetTowerOnMap(Tower curTower, int posx, int posy);
	void Attack(POINT pos);
	void UpgradeRange(float upg);
	void UpgradeDamage(float upg);
	void UpgradeFireRate(float upg);


	vector<Tower*> GetUsingTowerList() { return usingTower; }
	
};