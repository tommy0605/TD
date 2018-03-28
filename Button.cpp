#include "stdafx.h"

void Button::Init(string imageName, int x, int y, CALLBACK_FUNCTION cbFunction)
{
	callbackFunction = static_cast<CALLBACK_FUNCTION>(cbFunction);

	state = BTN_NULL;

	this->x = (float)x;
	this->y = (float)y;

	smallSize = 10;

	image = IMAGEMANAGER->FindImage(imageName);

	rc = RectMakeCenter(x, y, image->GetFrameW(), image->GetFrameH());

}

void Button::Update()
{
	if (PtInRect(&rc, mousePos))
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			state = BTN_DOWN;
		}
		else if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON))
		{
			if (state == BTN_DOWN)
			{
				state = BTN_UP;
				callbackFunction();
			}
		}
	}
	else
	{
		if(state != BTN_DOWN)
			state = BTN_NULL;
		if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON))
			state = BTN_UP;		
	}
}

void Button::Render(HDC hdc)
{
	switch (state)
	{
	case BTN_NULL:		
	case BTN_UP:
		image->Render(hdc, rc.left, rc.top);
		break;
	case BTN_DOWN:
	{
		RECT reSizeRc = RectMakeCenter(x, y,
			image->GetFrameW() - smallSize, image->GetFrameH() - smallSize);
		image->RenderSize(hdc, reSizeRc.left, reSizeRc.top,
			reSizeRc.right - reSizeRc.left, reSizeRc.bottom - reSizeRc.top);
	}
		break;
	default:
		break;
	}
}

void Button::Release()
{
}
