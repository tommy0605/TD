#include "stdafx.h"

ImageFont::ImageFont()
{

}

void ImageFont::Init(string key)
{
	image = IMAGEMANAGER->FindImage(key);
}

void ImageFont::Render(HDC hdc, int destX, int destY)
{
	string str = to_string(number);
	//char buffer[100];
	//char* str = itoa(number, buffer, 10);

	//atoi : ���ڸ� ���ڷ� �ٲٴ� �Լ�
	//itoa : ���ڸ� ���ڷ� �ٲٴ� �Լ�
	for (int i = 0; i < str.size(); i++)
	{
		int n = (int)str[i];
		n -= (int)'0';

		image->Render(hdc, destX + image->GetFrameW()*i, destY,
			n, 0);
	}
}
