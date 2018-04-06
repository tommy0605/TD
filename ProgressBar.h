#pragma once

class ProgressBar
{
private:
	Image * topImage;
	Image* bottomImage;
	POINT pos;
	POINT size;
	int width;

public:
	ProgressBar();
	void Init(int x, int y, int width, int height);
	void Update();
	void Render(HDC hdc);
	void SetGauge(int gage, float maxGage);

	inline void SetPos(POINT p) { pos = p; }
};