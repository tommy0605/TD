// stdafx.h : 자주 사용하지만 자주 변경되지는 않는
// 표준 시스템 포함 파일 또는 프로젝트 관련 포함 파일이
// 들어 있는 포함 파일입니다.

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용은 Windows 헤더에서 제외합니다.

#define WINSTARTX 0
#define WINSTARTY 0
#define WINWIDTH 800
#define WINHEIGHT 600

#define COLOR_P RGB(255, 0, 255)

#define PI 3.141592f

#define KEYMANAGER KeyManager::GetSingleton()
#define IMAGEMANAGER ImageManager::GetSingleton()
#define TIMEMANAGER TimeManager::GetSingleton()
#define EFFECTMANAGER EffectManager::GetSingleton()
#define SOUNDMANAGER SoundManager::GetSingleton()
#define SCENEMANAGER SceneManager::GetSingleton()
#define TEXTDATA TextData::GetSingleton()
// Windows 헤더 파일:
#include <windows.h>

// C 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <vector>
#include <time.h>

//Manager헤더파일/////////////
#include "SingletonBase.h"
#include "KeyManager.h"
#include "ImageManager.h"
#include "TimeManager.h"
#include "EffectManager.h"
#include "SoundManager.h"
#include "SceneManager.h"

//2DFrameWork헤더파일////////////////
#include "Image.h"
#include "BackBuffer.h"
#include "Animation.h"
#include "Effect.h"
#include "ImageFont.h"
#include "TextData.h"
#include "Button.h"


//MainGame헤더파일//////////////
#include "commonFunction.h"
#include "MainGame.h"

//Game헤더파일/////////////
#include "StartScene.h"
#include "GameScene.h"

#include "Tile.h"

extern HINSTANCE hInst;
extern HWND hWnd;
extern POINT mousePos;