#include "stdafx.h"

void Tower::Init(string name, float hp, BUILDNAME bname)
{
	bName = name;
	this->hp = hp;
	maxHp = hp;
	image = IMAGEMANAGER->FindImage(name);
	buildName = bname;
}

