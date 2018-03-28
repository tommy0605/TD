#pragma once

class GameNode
{
protected:
	BackBuffer * backBuffer;
public:
	virtual void Init();
	virtual void Update();
	virtual void Render(HDC hdc);
	virtual void Release();

	void SetBackBuffer();

	LRESULT MainProc(HWND, UINT, WPARAM, LPARAM);
};