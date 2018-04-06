#pragma once
#include "stdafx.h"

enum DIRECTION
{
	NONE = 10,
	UP,
	DOWN,
	RIGHT,
	LEFT,
	LEFT_TOP = 0,
	MIDDLE_TOP,
	RIGHT_TOP,
	LEFT_MIDDLE,
	MIDDLE_MIDDLE,
	RIGHT_MIDDLE,
	LEFT_BOTTOM,
	MIDDLE_BOTTOM,
	RIGHT_BOTTOM
};

inline DIRECTION GetCollisionDirection(RECT player, RECT obj)
{
	RECT rc;
	if (IntersectRect(&rc, &player, &obj))
	{
		int width = rc.right - rc.left;
		int height = rc.bottom - rc.top;

		if (width < height)
		{
			if (player.left > obj.left)
			{
				return RIGHT;
			}
			else
			{
				return LEFT;
			}
		}
		else
		{
			if (player.top > obj.top)
			{
				return DOWN;
			}
			else
			{
				return UP;
			}
		}
	}

	return NONE;
}

inline void MakeCeterCircle(HDC hdc, POINT pos, int radius)
{
	Ellipse(hdc, pos.x - radius, pos.y - radius, pos.x + radius, pos.y + radius);
}

inline RECT GetImageRect(POINT pos, int width, int height)
{
	RECT rc;
	rc.left = pos.x;
	rc.right = pos.x + width;
	rc.top = pos.y;
	rc.bottom = pos.y + height;

	return rc;
}

inline RECT RectMakeCenter(int x, int y, int width, int height)
{
	RECT rc = { x - (width / 2), y - (height / 2),
	x + (width / 2), y + (height / 2) };

	return rc;
}

inline RECT RectMake(int x, int y, int width, int height)
{
	return RECT{ x, y, x + width, y + height };
}

inline float GetDistance(float startX, float startY, float endX, float endY)
{
	float x = endX - startX;
	float y = endY - startY;

	return sqrtf(x*x + y * y);
}

inline float GetDistance(POINT a1, POINT a2)
{
	float x = a1.x - a2.x;
	float y = a2.y - a2.y;

	return sqrtf(x*x + y * y);
}

inline DIRECTION GetCollisionReposition(RECT* player, RECT* obj)
{
	RECT rc;
	if (IntersectRect(&rc, player, obj))
	{
		int width = rc.right - rc.left;
		int height = rc.bottom - rc.top;

		if (width < height)
		{
			if (player->left > obj->left)
			{
				player->left += width;
				player->right += width;
				return RIGHT;
			}
			else
			{
				player->left -= width;
				player->right -= width;
				return LEFT;
			}
		}
		else
		{
			if (player->top > obj->top)
			{
				player->top += height;
				player->bottom += height;
				return DOWN;
			}
			else
			{
				player->top -= height;
				player->bottom -= height;
				return UP;
			}
		}
	}

	return NONE;
}

inline float GetAngle(POINT pos1, POINT pos2)
{
	double dx = pos1.x - pos2.x;
	double dy = pos1.y - pos2.y;

	float angle = -(atan2(dy, dx));
	angle -= PI;

	return angle;
}