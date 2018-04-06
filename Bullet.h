#pragma once

struct Bullet
{
	Image* image;         //ÀÓ½Ã ±¸½½
	RECT rc;              //ÃÑ¾Ë Å©±â
	float angle;		  //ÃÑ¾Ë °¢µµ
	float speed;		  //ÃÑ¾Ë ¼Óµµ ±Ã±ØÀÇ ¼Óµµ
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
			image->Render(hdc, rc.left, rc.top, 0, 0);
		}
	}

	void SetRect()
	{
		rc.right = rc.left + image->GetW();
		rc.bottom = rc.top + image->GetH();
	}
	inline Image* GetBulletImage() { return image; }
};

class BulletManager
{
private:
	vector<Bullet*> bulletList;
	int bulletMax;
public:
	void Init(string imageName, int maxCount);
	void Update();
	void Render(HDC hdc);

	void Fire(POINT pos, float angle, float speed);

	bool IsCollision(RECT rc);

	inline vector<Bullet*> GetList() { return bulletList; }
};