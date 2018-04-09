#pragma once

struct Bullet
{
	RECT rc;				//ÃÑ¾Ë Å©±â
	float angle;			//ÃÑ¾Ë °¢µµ
	float speed;			//ÃÑ¾Ë ¼Óµµ ±Ã±ØÀÇ ¼Óµµ
	int size;
	bool isFire;		  //
	int count;			  //

	void Move()
	{
		if (isFire)
		{
			rc.left += cosf(angle)* speed;
			rc.top += -sinf(angle)* speed;
			if (rc.left >= WINWIDTH)
			{
				isFire = false;
			}
			SetRect();
		}
	}

	void Render(HDC hdc)
	{
		if (isFire)
		{
			Ellipse(hdc, rc.left, rc.top, rc.right, rc.bottom);
		}
	}

	void SetRect()
	{
		rc.right = rc.left + size;
		rc.bottom = rc.top + size;
	}
};

class BulletManager
{
private:
	vector<Bullet*> bulletList;
	COLORREF bc;
public:
	void Init(int size, COLORREF bcc);
	void Update();
	void Render(HDC hdc);

	void Fire(POINT pos, float angle, float speed);

	bool IsCollision(RECT rc);

	inline vector<Bullet*> GetList() { return bulletList; }
};