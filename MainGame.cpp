#include "stdafx.h"
#include "MainGame.h"

void MainGame::Init()
{
	GameNode::Init();		

	SCENEMANAGER->AddScene("start", new StartScene);
	SCENEMANAGER->AddScene("game", new GameScene);
	SCENEMANAGER->AddScene("maptool", new MapTool);
	
	SCENEMANAGER->ChangeScene("maptool");
	IMAGEMANAGER->AddImage("td", L"image/TDTOWER.bmp", 192, 230, 5, 6);
	IMAGEMANAGER->AddImage("gtd", L"image/gstd.bmp", 190, 152, 5, 4, true, RGB(255,0,255));
}

void MainGame::Update()
{
	GameNode::Update();
	/////////////////////////////


	/////////////////////////////
	SCENEMANAGER->Update();
	EFFECTMANAGER->Update();
}

void MainGame::Render(HDC hdc)
{
	HDC backDC = backBuffer->GetMemDC();
	PatBlt(backDC, 0, 0, WINWIDTH, WINHEIGHT, WHITENESS);
	////////////////////////////////////////////////
	
	
	///////////////////////////////////////////////////
	SCENEMANAGER->Render(backDC);
	EFFECTMANAGER->Render(backDC);
	TIMEMANAGER->Render(backDC);
	backBuffer->Render(hdc);
}

void MainGame::Release()
{
	GameNode::Release();
}