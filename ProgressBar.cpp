#include "stdafx.h"

ProgressBar::ProgressBar()
{
}

void ProgressBar::Init(int x, int y, int width, int height)
{
	pos.x = x;
	pos.y = y;
	topImage = IMAGEMANAGER->AddImage("front", L"Image/hpBarTop.bmp", width, height, true, RGB(255, 0, 255));
	bottomImage = IMAGEMANAGER->AddImage("back", L"Image/hpBarBottom.bmp", width, height, true, RGB(255, 0, 255));

	size.x = width;
	size.y = height;
}

void ProgressBar::Update()
{
}

void ProgressBar::Render(HDC hdc)
{
	bottomImage->RenderSize(hdc, pos.x, pos.y, size.x, size.y);
	topImage->RenderSize(hdc, pos.x, pos.y, width, size.y);
}

void ProgressBar::SetGauge(int gage, float maxGage)
{
	width = size.x *(gage / maxGage);
}
