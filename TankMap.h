#pragma once

class TankMap
{
private:
	Tile tile[TILEX*TILEY];
	
public:
	void Load();
	void Render(HDC hdc);

	inline Tile* GetTile() { return tile; }
};