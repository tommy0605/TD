#pragma once

class Unit
{
protected:
	Image * image;
	Image* colimage;
	COLORREF colCol;
	float hp;

public:
	void Init();
	void Render(HDC hdc);
	void Update();
	
	bool CheckEnemy();

};