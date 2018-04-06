#pragma once

class Tank
{
private:
	TankMap * tankMap;
	Image* image;
	POINT pos;
	int speed;

public:
	Tank();
	void Update();
	void Render(HDC hdc);
	void Move();
	POINT GetTilePos(POINT pos);
	bool IsWator(POINT pos);
	RECT GetRect();
	bool IsWator2(POINT pos);
	void CollisionCheck();

	inline void SetTankMap(TankMap* map) { tankMap = map; }
};