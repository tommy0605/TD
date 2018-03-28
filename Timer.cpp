#include "stdafx.h"
#include "Timer.h"
#include <mmsystem.h>

#pragma comment(lib, "winmm.lib")

void Timer::Init()
{
	//고해상도 타미어의 주기(1초당 진동 수)를 반환하는 함수
	if (QueryPerformanceFrequency((LARGE_INTEGER*)&periodFrequency))
	{
		isHardware = true;
		//일정 지점 안에서 몇번 진동 하였는가를 나타내는 함수
		QueryPerformanceCounter((LARGE_INTEGER*)&lastTime);

		timeScale = 1.0f / periodFrequency;
	}
	else
	{
		isHardware = false;

		lastTime = timeGetTime();
		timeScale = 0.001f;
	}

	frameRate = 0;
	FPSframeCount = 0;
	FPSTimeElapsed = 0;
	worldTime = 0;
}

void Timer::Tick(float lockFPS)
{
	if (isHardware)
	{
		QueryPerformanceCounter((LARGE_INTEGER*)&curTime);
	}
	else
	{
		curTime = timeGetTime();
	}

	timeElapsed = (curTime - lastTime) * timeScale;

	if (lockFPS > 0)
	{
		while (timeElapsed < (1.0f / lockFPS))
		{
			if (isHardware)
			{
				QueryPerformanceCounter((LARGE_INTEGER*)&curTime);
			}
			else
			{
				curTime = timeGetTime();
			}

			timeElapsed = (curTime - lastTime) * timeScale;
		}
	}

	lastTime = curTime;
	FPSframeCount++;
	FPSTimeElapsed += timeElapsed;
	worldTime += timeElapsed;

	if (FPSTimeElapsed > 1.0f)
	{
		frameRate = FPSframeCount;
		FPSframeCount = 0;
		FPSTimeElapsed = 0;
	}
}
