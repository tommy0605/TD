#include "stdafx.h"

Image::Image()
{
	hMemDC = NULL;
	hBit = NULL;
	hOldBit = NULL;
	width = 0;
	height = 0;
	currentFrameX = 0;
	currentFrameY = 0;
	maxFrameX = 0;
	maxFrameY = 0;
	frameWidth = 0;
	frameHeight = 0;

	isTrans = false;
	transColor = RGB(0, 0, 0);
}

void Image::Init(const TCHAR * _fileName, int _width, int _height, bool _isTrans, COLORREF _transColor)
{
	HDC hdc = GetDC(hWnd);

	hMemDC = CreateCompatibleDC(hdc);
	hBit = (HBITMAP)LoadImage(hInst, _fileName, IMAGE_BITMAP,
		_width, _height, LR_LOADFROMFILE);
	hOldBit = (HBITMAP)SelectObject(hMemDC, hBit);

	width = _width;
	height = _height;
	frameWidth = _width;
	frameHeight = _height;

	isTrans = _isTrans;
	transColor = _transColor;

	//알파블렌드 셋팅
	hAlphaMemDC = CreateCompatibleDC(hdc);
	hAlphaBit = CreateCompatibleBitmap(hdc, WINWIDTH, WINHEIGHT);
	hOldBit = (HBITMAP)SelectObject(hAlphaMemDC, hAlphaBit);

	ReleaseDC(hWnd, hdc);
}

void Image::Init(const TCHAR * _fileName, int _width, int _height, int _maxFrameX, int _maxFrameY, bool _isTrans, COLORREF _transColor)
{
	HDC hdc = GetDC(hWnd);

	hMemDC = CreateCompatibleDC(hdc);
	hBit = (HBITMAP)LoadImage(hInst, _fileName, IMAGE_BITMAP,
		_width, _height, LR_LOADFROMFILE);
	hOldBit = (HBITMAP)SelectObject(hMemDC, hBit);

	width = _width;
	height = _height;
	frameWidth = _width / _maxFrameX;
	frameHeight = _height / _maxFrameY;
	maxFrameX = _maxFrameX;
	maxFrameY = _maxFrameY;

	isTrans = _isTrans;
	transColor = _transColor;

	//알파블렌드 셋팅
	hAlphaMemDC = CreateCompatibleDC(hdc);
	hAlphaBit = CreateCompatibleBitmap(hdc, WINWIDTH, WINHEIGHT);
	hOldBit = (HBITMAP)SelectObject(hAlphaMemDC, hAlphaBit);

	ReleaseDC(hWnd, hdc);
}

void Image::Release()
{
	SelectObject(hMemDC, hOldBit);
	DeleteObject(hBit);
	DeleteDC(hMemDC);
}

void Image::Render(HDC hdc, int destX, int destY)
{
	if (isTrans)
	{
		GdiTransparentBlt(
			hdc, destX, destY, width, height,
			hMemDC,
			0, 0, width, height, transColor
		);
	}
	else
	{
		BitBlt(hdc, destX, destY, width, height,
			hMemDC, 0, 0, SRCCOPY);
	}
}

void Image::Render(HDC hdc, int destX, int destY, int frameX, int frameY)
{
	if (isTrans)
	{
		GdiTransparentBlt(
			hdc, destX, destY,
			frameWidth, frameHeight,
			hMemDC,
			frameWidth * frameX,
			frameHeight * frameY,
			frameWidth, frameHeight,
			transColor
		);
	}
	else
	{
		BitBlt(hdc, destX, destY, frameWidth, frameHeight,
			hMemDC, frameWidth * frameX, frameHeight * frameY,
			SRCCOPY);
	}
}

void Image::Render(HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight)
{
	if (isTrans)
	{
		GdiTransparentBlt(
			hdc, destX, destY,
			sourWidth, sourHeight,
			hMemDC,
			sourX,
			sourY,
			sourWidth, sourHeight,
			transColor
		);
	}
	else
	{
		BitBlt(hdc, destX, destY, sourWidth, sourHeight,
			hMemDC, 
			sourX,
			sourY,
			SRCCOPY);
	}
}

void Image::RenderSize(HDC hdc, int destX, int destY, int width, int height)
{
	if (isTrans)
	{
		GdiTransparentBlt(
			hdc, destX, destY, width, height,
			hMemDC,
			0, 0, this->width, this->height,
			transColor
		);
	}
	else
	{
		//BitBlt(hdc, destX, destY, width, height,
			//hMemDC, 0, 0, SRCCOPY);
		StretchBlt(hdc, destX, destY, width, height,
			hMemDC, 0, 0, this->width, this->height, SRCCOPY);
	}
}

void Image::RenderSize(HDC hdc, int destX, int destY, int frameX, int frameY, int width, int height)
{
	if (isTrans)
	{
		GdiTransparentBlt(
			hdc, destX, destY,
			width, height,
			hMemDC,
			frameWidth * frameX,
			frameHeight * frameY,
			frameWidth, frameHeight,
			transColor
		);
	}
	else
	{
		//BitBlt(hdc, destX, destY, width, height,
			//hMemDC, frameWidth * frameX, frameHeight * frameY,	SRCCOPY);
		StretchBlt(hdc, destX, destY, width, height,
			hMemDC, frameWidth * frameX, frameHeight * frameY,
			frameWidth, frameHeight, SRCCOPY);
	}
}

void Image::CenterPosRender(HDC hdc, POINT pos, int width, int height)
{
	if (isTrans)
	{
		GdiTransparentBlt(
			hdc, pos.x - this->GetW() / 2, pos.y - this->GetH() / 2, width, height,
			hMemDC,
			0, 0, this->width, this->height,
			transColor
		);
	}
	else
	{
		StretchBlt(hdc, pos.x - this->GetW() / 2, pos.y - this->GetH() / 2, width, height,
			hMemDC, 0, 0, this->width, this->height, SRCCOPY);
	}
}

void Image::CenterPosRender(HDC hdc, POINT pos, int frameX, int frameY, int width, int height)
{
	if (isTrans)
	{
		GdiTransparentBlt(
			hdc, pos.x - this->GetFrameW()/2, pos.y - this->GetFrameH() / 2,
			width, height,
			hMemDC,
			frameWidth * frameX,
			frameHeight * frameY,
			frameWidth, frameHeight,
			transColor
		);
	}
	else
	{
		StretchBlt(hdc, pos.x - this->GetFrameW() / 2, pos.y - this->GetFrameH() / 2, width, height,
			hMemDC, frameWidth * frameX, frameHeight * frameY,
			frameWidth, frameHeight, SRCCOPY);
	}
}

//alpha : 0~255 (0이면 투명, 255면 불투명)
void Image::AlphaRender(HDC hdc, int destX, int destY, int alpha)
{
	blendFunc.SourceConstantAlpha = (BYTE)alpha;

	if (isTrans)
	{
		BitBlt(hAlphaMemDC, 0, 0, width, height,
			hdc, destX, destY, SRCCOPY);

		GdiTransparentBlt(hAlphaMemDC, 0, 0, width, height,
			hMemDC, 0, 0, width, height, transColor);

		GdiAlphaBlend(hdc, destX, destY, width, height,
			hAlphaMemDC, 0, 0, width, height, blendFunc);
	}
	else
	{
		GdiAlphaBlend(hdc, destX, destY, width, height,
			hMemDC, 0, 0, width, height, blendFunc);
	}
}

void Image::AlphaRender(HDC hdc, int destX, int destY, int frameX, int frameY, int alpha)
{
	blendFunc.SourceConstantAlpha = (BYTE)alpha;

	if (isTrans)
	{
		BitBlt(hAlphaMemDC, 0, 0, width, height,
			hdc, destX, destY, SRCCOPY);

		GdiTransparentBlt(hAlphaMemDC, 0, 0, frameWidth, frameHeight,
			hMemDC, frameWidth * frameX, frameHeight * frameY,
			frameWidth, frameHeight,
			transColor);

		GdiAlphaBlend(hdc, destX, destY, 
			frameWidth, frameHeight,
			hAlphaMemDC, 0, 0, frameWidth, frameHeight,
			blendFunc);
	}
	else
	{
		GdiAlphaBlend(hdc, destX, destY, frameWidth, frameHeight,
			hMemDC, frameWidth * frameX, frameHeight*frameY,
			frameWidth, frameHeight, blendFunc);
	}
}

void Image::AniRender(HDC hdc, int destX, int destY, Animation * ani)
{
	if (isTrans)
	{
		GdiTransparentBlt(
			hdc, destX, destY,
			frameWidth, frameHeight,
			hMemDC,
			ani->GetFramePos().x,
			ani->GetFramePos().y,
			frameWidth, frameHeight,
			transColor
		);
	}
	else
	{
		BitBlt(hdc, destX, destY, frameWidth, frameHeight,
			hMemDC, ani->GetFramePos().x, ani->GetFramePos().y,
			SRCCOPY);
	}
}
