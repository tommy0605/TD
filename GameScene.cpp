#include "stdafx.h"

void GameScene::Init()
{
	map = new MapTool;
	map->SetTile();
	map->LoadMap();
	map->SetSE();
	isPause = true;
}

void GameScene::Update()
{
}

void GameScene::Render(HDC hdc)
{
	HBRUSH hBrush, hOldBrush;
	hBrush = CreateSolidBrush(RGB(30, 30, 30));
	hOldBrush = (HBRUSH)SelectObject(hdc, hBrush);
	Rectangle(hdc, 0, 0, WINWIDTH, WINHEIGHT);
	SelectObject(hdc, hOldBrush);
	DeleteObject(hBrush);
	DeleteObject(hOldBrush);

	map->TotalRender(hdc);
	IMAGEMANAGER->FindImage("gtd")->Render(hdc,0,0);
}

void GameScene::Release()
{
}
