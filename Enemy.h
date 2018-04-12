#pragma once

enum TYPE
{
	SPEED,
	HEALTH,
	BALANCE,
	BONUS,
	HEALTH2,
	BALANCE2
};

class Enemy
{
private:
	float hp;
	Image* image;
	float speed;
	TYPE type;
	int frameX;
	int frameY;
	POINT pos;
	POINT nextPos;
	bool isAlive;
	bool isGamed;
	
public:
	void Init(int num);
	void Update();
	void Move();
	void Render(HDC hdc);
	void DOA(HDC hdc);
	
	void Upgrade(float dif);
	inline POINT GetPos() { return pos; }
	inline void SetNextPos(POINT poss) { nextPos = poss; }
	inline bool GetIsAlive() { return isAlive; }
	inline void SetAlive(bool isAliv) { isAlive = isAliv; }
	inline bool GetIsGamed() { return isGamed; }
	inline void SetGamed(bool gamed) { isAlive = gamed; }
};