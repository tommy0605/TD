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

	TCHAR str[128] = L"����� ��ŸƮ ��";
		
	HFONT hFont, hOldFont;
	HFONT hFont2;
	hFont = CreateFont(
		40, //���� ���� ��
		0,	//���� ���� ��
		0,	//���� ����
		0,	//���� ����
		600, //���� ����
		0,	//bool�� ���� ����
		0,	//bool�� ���� ����
		0,	//bool�� ���� ��Ҽ�
		HANGUL_CHARSET,	//���� ����
		100,	//���� ��� ��Ȯ��
		0,		//Ŭ���� ��Ȯ��
		0,		//��� ����Ƽ
		0,		//�ڰ�
		TEXT("��������ڵ�")
	);

	hOldFont = (HFONT)SelectObject(hdc, hFont);

	TextOut(hdc, 200, 180, str, wcslen(str));

	SelectObject(hdc, hOldFont);

	hFont2 = CreateFont(
		40, //���� ���� ��
		0,	//���� ���� ��
		0,	//���� ����
		0,	//���� ����
		600, //���� ����
		0,	//bool�� ���� ����
		0,	//bool�� ���� ����
		0,	//bool�� ���� ��Ҽ�
		HANGUL_CHARSET,	//���� ����
		100,	//���� ��� ��Ȯ��
		100,		//Ŭ���� ��Ȯ��
		0,		//��� ����Ƽ
		0,		//�ڰ�
		TEXT("����ü")
	);

	hOldFont = (HFONT)SelectObject(hdc, hFont2);

	TextOut(hdc, 200, 100, str, wcslen(str));

	SelectObject(hdc, hOldFont);
}

void StartScene::ChangeScene()
{
	SCENEMANAGER->ChangeScene("game");
}
