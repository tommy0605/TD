#pragma once
#include <functional>

enum BUTTONSTATE
{
	BTN_NULL,
	BTN_UP,
	BTN_DOWN
};

//typedef void(*CALLBACK_FUNCTION)(void);
typedef function<void()> CALLBACK_FUNCTION;

class Button
{
private:
	BUTTONSTATE state;

	Image* image;
	RECT rc;
	float x, y;

	int smallSize;

	//void(*callBackFunction)();	
	CALLBACK_FUNCTION callbackFunction;
	

public:
	void Init(string imageName, int x, int y, CALLBACK_FUNCTION cbFunction);

	void Update();
	void Render(HDC hdc);
	void Release();
};