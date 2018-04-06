#pragma once

class TankGame : public GameNode
{
private:
	TankMap * tankMap;
	Tank* tank;

public:
	void Init();
	void Update();
	void Render(HDC hdc);
	void Release();
};