#pragma once

class ImageFont
{
private:
	Image * image;
	int number;

public:
	ImageFont();
	void Init(string key);
	void Render(HDC hdc, int destX, int destY);

	inline void SetNumber(int num) { number = num; }

};