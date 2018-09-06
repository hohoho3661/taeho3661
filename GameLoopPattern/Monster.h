#pragma once

class Image;

class Monster
{
	Image*	_monster;

	int		_nCount;
	int		_iIndex;

	int		_dirChange;

public:
	Monster();
	virtual ~Monster();

	virtual void Update();
	virtual void Render(HDC hdc);
};

