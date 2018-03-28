#include "stdafx.h"

void StartScene::Init()
{
	IMAGEMANAGER->AddImage("btn", L"Image/button.bmp", 300, 300,
		true, RGB(255, 255, 255));

	startBtn = new Button;
	startBtn->Init("btn", WINWIDTH / 2, WINHEIGHT / 2,
		bind(&StartScene::ChangeScene, this));
}

void StartScene::Release()
{
}

void StartScene::Update()
{
	startBtn->Update();
}

void StartScene::Render(HDC hdc)
{	
	startBtn->Render(hdc);

	TCHAR str[128] = L"여기는 스타트 씬";
		
	HFONT hFont, hOldFont;
	HFONT hFont2;
	hFont = CreateFont(
		40, //문자 세로 폭
		0,	//문자 가로 폭
		0,	//문자 기울기
		0,	//문자 방향
		600, //문자 굵기
		0,	//bool형 문자 기울기
		0,	//bool형 문자 밑줄
		0,	//bool형 문자 취소선
		HANGUL_CHARSET,	//문자 세팅
		100,	//문자 출력 정확도
		0,		//클리핑 정확도
		0,		//출력 퀄리티
		0,		//자간
		TEXT("나눔고딕코딩")
	);

	hOldFont = (HFONT)SelectObject(hdc, hFont);

	TextOut(hdc, 200, 180, str, wcslen(str));

	SelectObject(hdc, hOldFont);

	hFont2 = CreateFont(
		40, //문자 세로 폭
		0,	//문자 가로 폭
		0,	//문자 기울기
		0,	//문자 방향
		600, //문자 굵기
		0,	//bool형 문자 기울기
		0,	//bool형 문자 밑줄
		0,	//bool형 문자 취소선
		HANGUL_CHARSET,	//문자 세팅
		100,	//문자 출력 정확도
		100,		//클리핑 정확도
		0,		//출력 퀄리티
		0,		//자간
		TEXT("돋움체")
	);

	hOldFont = (HFONT)SelectObject(hdc, hFont2);

	TextOut(hdc, 200, 100, str, wcslen(str));

	SelectObject(hdc, hOldFont);
}

void StartScene::ChangeScene()
{
	SCENEMANAGER->ChangeScene("game");
}
