#include "stdafx.h"
#define BULLETSIZE 20
#define FIRERATEM 5.0f
#define RANGE 200.0f
#define TOWERDAMAGE 200.0f


void BuildingManager::Init()
{
	Tower tower;
	string str = "lone";
	tower.Init(str, 100, LONE, 0, 0, 0, 1, 20.0f, FIRERATEM*2, RANGE/4, BULLETSIZE/2, RGB(0,150,0), TOWERDAMAGE/4);
	towerList.insert(make_pair(str, tower));
	str = "ltwo";
	tower.Init(str, 100, LTWO, 0, 2, 0, 3, 25.0f, FIRERATEM*2 -1.0f, RANGE/4, BULLETSIZE/2, RGB(0, 150, 0), TOWERDAMAGE / 4 + 7.0f);
	towerList.insert(make_pair(str, tower));
	str = "lthr";
	tower.Init(str, 100, LTHR, 0, 4, 0, 5, 30.0f, FIRERATEM*2 - 2.0f, RANGE/4, BULLETSIZE/2, RGB(0, 150, 0), TOWERDAMAGE / 4 + 10.0f);
	towerList.insert(make_pair(str, tower));
	str = "drlone";
	tower.Init(str, 100, DRLONE, 1, 0, 1, 1, 40.0f, FIRERATEM, RANGE/5, BULLETSIZE/4, RGB(150, 20, 150), TOWERDAMAGE / 5);
	towerList.insert(make_pair(str, tower));
	str = "drltwo";
	tower.Init(str, 100, DRLTWO, 1, 2, 1, 3, 45.0f, FIRERATEM - 1.0f, RANGE/5, BULLETSIZE/4, RGB(150, 20, 150), TOWERDAMAGE / 5 + 3.0f);
	towerList.insert(make_pair(str, tower));
	str = "drlthr";
	tower.Init(str, 100, DRLTHR, 1, 4, 1, 5, 50.0f, FIRERATEM - 2.0f, RANGE/5, BULLETSIZE/4, RGB(150, 20, 150), TOWERDAMAGE / 5 + 5.0f);
	towerList.insert(make_pair(str, tower));
	str = "splone";
	tower.Init(str, 100, SPLONE, 4, 4, 4, 5, 20.0f, FIRERATEM*4, RANGE/2, BULLETSIZE, RGB(150, 20, 20), TOWERDAMAGE / 2);
	towerList.insert(make_pair(str, tower));
	str = "spltwo";
	tower.Init(str, 100, SPLTWO, 2, 0, 2, 1, 25.0f, FIRERATEM*4-1.0f, RANGE/2, BULLETSIZE, RGB(150, 20, 20), TOWERDAMAGE / 2 + 30.0f);
	towerList.insert(make_pair(str, tower));
	str = "splthr";
	tower.Init(str, 100, SPLTHR, 2, 2, 2, 3, 30.0f, FIRERATEM*4-2.0f, RANGE/2, BULLETSIZE, RGB(150, 20, 20), TOWERDAMAGE / 2 + 50.0f);
	towerList.insert(make_pair(str, tower));
	str = "snpone";
	tower.Init(str, 100, SNPONE, 4, 0, 4, 1, 100.0f, FIRERATEM*4, RANGE, BULLETSIZE/2, RGB(20, 20, 150), TOWERDAMAGE);
	towerList.insert(make_pair(str, tower));
	str = "spntwo";
	tower.Init(str, 100, SNPTWO, 4, 2, 4, 3, 100.0f, FIRERATEM*4-1.0f, RANGE, BULLETSIZE/2, RGB(20, 20, 150), TOWERDAMAGE + 100.0f);
	towerList.insert(make_pair(str, tower));
}

void BuildingManager::Update()
{
}

void BuildingManager::Render(HDC hdc)
{
	int i = 0;
	towerList.find("lone")->second.Render(hdc, WINWIDTH - IMAGEMANAGER->FindImage("td")->GetFrameW(), 0 + i * IMAGEMANAGER->FindImage("td")->GetFrameH());
	towerList.find("lone")->second.rc = RectMake(WINWIDTH - IMAGEMANAGER->FindImage("td")->GetFrameW(), 0 + i * IMAGEMANAGER->FindImage("td")->GetFrameH(), IMAGEMANAGER->FindImage("td")->GetFrameW(), IMAGEMANAGER->FindImage("td")->GetFrameH());
	i++;
	towerList.find("ltwo")->second.Render(hdc, WINWIDTH - IMAGEMANAGER->FindImage("td")->GetFrameW(), 0 + i * IMAGEMANAGER->FindImage("td")->GetFrameH());
	towerList.find("ltwo")->second.rc = RectMake(WINWIDTH - IMAGEMANAGER->FindImage("td")->GetFrameW(), 0 + i * IMAGEMANAGER->FindImage("td")->GetFrameH(), IMAGEMANAGER->FindImage("td")->GetFrameW(), IMAGEMANAGER->FindImage("td")->GetFrameH());
	i++;
	towerList.find("lthr")->second.Render(hdc, WINWIDTH - IMAGEMANAGER->FindImage("td")->GetFrameW(), 0 + i * IMAGEMANAGER->FindImage("td")->GetFrameH());
	towerList.find("lthr")->second.rc = RectMake(WINWIDTH - IMAGEMANAGER->FindImage("td")->GetFrameW(), 0 + i * IMAGEMANAGER->FindImage("td")->GetFrameH(), IMAGEMANAGER->FindImage("td")->GetFrameW(), IMAGEMANAGER->FindImage("td")->GetFrameH());
	i++;
	towerList.find("drlone")->second.Render(hdc, WINWIDTH - IMAGEMANAGER->FindImage("td")->GetFrameW(), 0 + i * IMAGEMANAGER->FindImage("td")->GetFrameH());
	towerList.find("drlone")->second.rc = RectMake(WINWIDTH - IMAGEMANAGER->FindImage("td")->GetFrameW(), 0 + i * IMAGEMANAGER->FindImage("td")->GetFrameH(), IMAGEMANAGER->FindImage("td")->GetFrameW(), IMAGEMANAGER->FindImage("td")->GetFrameH());
	i++;
	towerList.find("drltwo")->second.Render(hdc, WINWIDTH - IMAGEMANAGER->FindImage("td")->GetFrameW(), 0 + i * IMAGEMANAGER->FindImage("td")->GetFrameH());
	towerList.find("drltwo")->second.rc = RectMake(WINWIDTH - IMAGEMANAGER->FindImage("td")->GetFrameW(), 0 + i * IMAGEMANAGER->FindImage("td")->GetFrameH(), IMAGEMANAGER->FindImage("td")->GetFrameW(), IMAGEMANAGER->FindImage("td")->GetFrameH());
	i++;
	towerList.find("drlthr")->second.Render(hdc, WINWIDTH - IMAGEMANAGER->FindImage("td")->GetFrameW(), 0 + i * IMAGEMANAGER->FindImage("td")->GetFrameH());
	towerList.find("drlthr")->second.rc = RectMake(WINWIDTH - IMAGEMANAGER->FindImage("td")->GetFrameW(), 0 + i * IMAGEMANAGER->FindImage("td")->GetFrameH(), IMAGEMANAGER->FindImage("td")->GetFrameW(), IMAGEMANAGER->FindImage("td")->GetFrameH());
	i++;
	towerList.find("splone")->second.Render(hdc, WINWIDTH - IMAGEMANAGER->FindImage("td")->GetFrameW(), 0 + i * IMAGEMANAGER->FindImage("td")->GetFrameH());
	towerList.find("splone")->second.rc = RectMake(WINWIDTH - IMAGEMANAGER->FindImage("td")->GetFrameW(), 0 + i * IMAGEMANAGER->FindImage("td")->GetFrameH(), IMAGEMANAGER->FindImage("td")->GetFrameW(), IMAGEMANAGER->FindImage("td")->GetFrameH());
	i++;
	towerList.find("spltwo")->second.Render(hdc, WINWIDTH - IMAGEMANAGER->FindImage("td")->GetFrameW(), 0 + i * IMAGEMANAGER->FindImage("td")->GetFrameH());
	towerList.find("spltwo")->second.rc = RectMake(WINWIDTH - IMAGEMANAGER->FindImage("td")->GetFrameW(), 0 + i * IMAGEMANAGER->FindImage("td")->GetFrameH(), IMAGEMANAGER->FindImage("td")->GetFrameW(), IMAGEMANAGER->FindImage("td")->GetFrameH());
	i++;
	towerList.find("splthr")->second.Render(hdc, WINWIDTH - IMAGEMANAGER->FindImage("td")->GetFrameW(), 0 + i * IMAGEMANAGER->FindImage("td")->GetFrameH());
	towerList.find("splthr")->second.rc = RectMake(WINWIDTH - IMAGEMANAGER->FindImage("td")->GetFrameW(), 0 + i * IMAGEMANAGER->FindImage("td")->GetFrameH(), IMAGEMANAGER->FindImage("td")->GetFrameW(), IMAGEMANAGER->FindImage("td")->GetFrameH());
	i++;
	towerList.find("snpone")->second.Render(hdc, WINWIDTH - IMAGEMANAGER->FindImage("td")->GetFrameW(), 0 + i * IMAGEMANAGER->FindImage("td")->GetFrameH());
	towerList.find("snpone")->second.rc = RectMake(WINWIDTH - IMAGEMANAGER->FindImage("td")->GetFrameW(), 0 + i * IMAGEMANAGER->FindImage("td")->GetFrameH(), IMAGEMANAGER->FindImage("td")->GetFrameW(), IMAGEMANAGER->FindImage("td")->GetFrameH());
	i++;
	towerList.find("spntwo")->second.Render(hdc, WINWIDTH - IMAGEMANAGER->FindImage("td")->GetFrameW(), 0 + i * IMAGEMANAGER->FindImage("td")->GetFrameH());
	towerList.find("spntwo")->second.rc = RectMake(WINWIDTH - IMAGEMANAGER->FindImage("td")->GetFrameW(), 0 + i * IMAGEMANAGER->FindImage("td")->GetFrameH(), IMAGEMANAGER->FindImage("td")->GetFrameW(), IMAGEMANAGER->FindImage("td")->GetFrameH());
	i++;

	for (int i = 0; i < usingTower.size(); i++)
	{
		usingTower[i]->GameRender(hdc, usingTower[i]->pos.x, usingTower[i]->pos.y);
		usingTower[i]->Update(hdc);
	}

}

Tower* BuildingManager::FindTower(string key)
{
	map<string, Tower>::iterator it;
	it = towerList.find(key);

	//이미지 찾았을 경우
	if (it != towerList.end())
	{
		return &it->second;
	}

	return NULL;
}

Tower* BuildingManager::SetCurrTower()
{
	map<string, Tower>::iterator it;
	for (it = towerList.begin(); it != towerList.end(); it++)
	{
		if (PtInRect(&it->second.rc, mousePos))
		{
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				return &it->second;
				break;
			}
		}
	}
}

void BuildingManager::SetTowerOnMap(Tower curTower, int posx, int posy)
{
	Tower* tower = new Tower;
	*tower = curTower;
	tower->pos.x = posx;
	tower->pos.y = posy;
	usingTower.push_back(tower);
}

void BuildingManager::Attack(POINT pos)
{
	for (int i = 0; i < usingTower.size(); i++)
	{
		usingTower[i]->CheckEnemy(pos);
	}
}

void BuildingManager::UpgradeRange(float upg)
{
	for (int i = 0; i < usingTower.size(); i++)
	{
		usingTower[i]->range += upg;
	}
}

void BuildingManager::UpgradeDamage(float upg)
{
	for (int i = 0; i < usingTower.size(); i++)
	{
		usingTower[i]->damage+= upg;
	}
}

void BuildingManager::UpgradeFireRate(float upg)
{
	for (int i = 0; i < usingTower.size(); i++)
	{
		usingTower[i]->fireRate += upg;
	}
}


