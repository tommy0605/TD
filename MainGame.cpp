#include "stdafx.h"
#include "MainGame.h"

void MainGame::Init()
{
	GameNode::Init();		

	SCENEMANAGER->AddScene("start", new StartScene);
	SCENEMANAGER->AddScene("game", new GameScene);

	SCENEMANAGER->ChangeScene("start");
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