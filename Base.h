#pragma once

class Base
{
private:
	Image * image;
	BulletManager* bm;
	RECT rc;

public:
	~Base();
	void Update();
	void Render(HDC hdc);
	

	void Attack(float angle);

};