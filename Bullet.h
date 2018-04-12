#pragma once

struct Bullet
{
	RECT rc;				//�Ѿ� ũ��
	float angle;			//�Ѿ� ����
	float speed;			//�Ѿ� �ӵ� �ñ��� �ӵ�
	int size;
	bool isFire;		  //
	int count;			  //
	float damage;

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
	void Init(int size, COLORREF bcc, float damage);
	void Update();
	void Render(HDC hdc);

	void Fire(POINT pos, float angle, float speed, float damage);

	bool IsCollision(RECT rc);

	inline vector<Bullet*> GetList() { return bulletList; }
};