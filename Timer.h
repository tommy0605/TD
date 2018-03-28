#pragma once

//FPS(Frame Per Second) : 초당 프레임 빈도 수
class Timer
{
private:
	bool isHardware;	//고성능 하드웨어 지원여부
	float timeScale;	//FPS빈도
	float timeElapsed;	//Tick Count

	__int64 curTime;			//현재시간
	__int64 lastTime;			//마지막 시간
	__int64 periodFrequency;	//빈도

	unsigned long frameRate;
	unsigned long FPSframeCount;

	float FPSTimeElapsed;
	float worldTime;

public:
	void Init();
	void Tick(float lockFPS = 0.0f);

	inline unsigned long GetFrameRate() const {	return frameRate; }
	inline float GetElapsedTime() const { return timeElapsed; }
	inline float GetWorldTime() const { return worldTime; }
};