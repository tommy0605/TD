#include "stdafx.h"

void TankMap::Load()
{
	HANDLE file;
	DWORD read;

	file = CreateFile(L"mapData.map", GENERIC_READ, NULL, NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	ReadFile(file, tile, sizeof(Tile)*TILEX*TILEY, &read, NULL);

	CloseHandle(file);
}

void TankMap::Render(HDC hdc)
{
	for (int i = 0; i < TILEX*TILEY; i++)
	{
		IMAGEMANAGER->Render("tile", hdc, tile[i].rc.left, tile[i].rc.top,
			tile[i].frameX, tile[i].frameY);
	}
}
