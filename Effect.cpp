#include "stdafx.h"

Effect::Effect()
{
	image = NULL;
	ani = NULL;
	isRun = false;
	pos.x = 0;
	pos.y = 0;
}

void Effect::Init(Image * effectImage, int fps)
{
	if (!effectImage)
		return;

	isRun = false;
	image = effectImage;
	elapsedTime = 1.0f;

	if (!ani)
		ani = new Animation;

	ani->Init(image);
	ani->SetDefPlayFrame();
	ani->SetFPS(fps);
	ani->Stop();
}

void Effect::Release()
{
	image = NULL;
	delete ani;
}

void Effect::Update()
{
	if (isRun)
	{
		ani->FrameUpdate(elapsedTime);
		if (!ani->GetIsPlay())
			KillEffect();
	}
}

void Effect::Render(HDC hdc)
{
	if (isRun)
		image->AniRender(hdc, pos.x, pos.y, ani);
}

void Effect::StartEffect(POINT pos)
{
	if (!image || !ani)
		return;

	this->pos.x = pos.x - (ani->GetFrameWidth() / 2);
	this->pos.y = pos.y - (ani->GetFrameHeight() / 2);

	isRun = true;
	ani->Start();
}

void Effect::KillEffect()
{
	isRun = false;
}
