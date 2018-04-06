#include "stdafx.h"

void BuildingManager::Init()
{
	Tower tower;
	string str = "lone";
	tower.Init(str, 100, LONE, 0, 0, 0, 1);
	towerList.insert(make_pair(str, tower));
	str = "ltwo";
	tower.Init(str, 100, LTWO, 0, 2, 0, 3);
	towerList.insert(make_pair(str, tower));
	str = "lthr";
	tower.Init(str, 100, LTHR, 0, 4, 0, 5);
	towerList.insert(make_pair(str, tower));
	str = "drlone";
	tower.Init(str, 100, DRLONE, 1, 0, 1, 1);
	towerList.insert(make_pair(str, tower));
	str = "drltwo";
	tower.Init(str, 100, DRLTWO, 1, 2, 1, 3);
	towerList.insert(make_pair(str, tower));
	str = "drlthr";
	tower.Init(str, 100, DRLTHR, 1, 4, 1, 5);
	towerList.insert(make_pair(str, tower));
	str = "splone";
	tower.Init(str, 100, SPLONE, 4, 4, 4, 5);
	towerList.insert(make_pair(str, tower));
	str = "spltwo";
	tower.Init(str, 100, SPLTWO, 2, 0, 2, 1);
	towerList.insert(make_pair(str, tower));
	str = "splthr";
	tower.Init(str, 100, SPLTHR, 2, 2, 2, 3);
	towerList.insert(make_pair(str, tower));
	str = "snpone";
	tower.Init(str, 100, SNPONE, 4, 0, 4, 1);
	towerList.insert(make_pair(str, tower));
	str = "spntwo";
	tower.Init(str, 100, SNPTWO, 4, 2, 4, 3);
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
