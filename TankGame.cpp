#include "stdafx.h"

void TankGame::Init()
{
	tankMap = new TankMap();
	tankMap->Load();
	tank = new Tank;
	tank->SetTankMap(tankMap);
}

void TankGame::Update()
{
	tank->Update();
}

void TankGame::Render(HDC hdc)
{
	tankMap->Render(hdc);
	tank->Render(hdc);
}

void TankGame::Release()
{
	delete tankMap;
	delete tank;
}
