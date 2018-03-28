#pragma once
#include "SingletonBase.h"
#include "Image.h"
#include <map>

using namespace std;

class ImageManager : public SingletonBase<ImageManager>
{
private:
	map<string, Image*> imageList;

public:
	Image * AddImage(string strKey, const TCHAR* fileName, int width, int height,
		bool isTrans = false, COLORREF transColor = NULL);
	Image * AddImage(string strKey, const TCHAR* fileName, int width, int height,
		int frameX, int frameY, bool isTrans = false, COLORREF transColor = NULL);

	Image* FindImage(string strKey);

	void DeleteAll();
	void DeleteImage(string strKey);
	void Release();

	void Render(string strKey, HDC hdc, int destX, int destY);
	void Render(string strKey, HDC hdc, int destX, int destY,
		int frameX, int frameY);
	void RenderSize(string strKey, HDC hdc, int destX, int destY, int widht, int height);
	void RenderSize(string strKey, HDC hdc, int destX, int destY,
		int frameX, int frameY, int width, int height);
};