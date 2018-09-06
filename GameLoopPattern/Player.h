#pragma once

class Image;

class Player
{
	Image*	_siva;
	
	int		_nCount;
	int		_iIndex;

	int		_dirChange;

public:
	Player();
	virtual ~Player();
	
	virtual void Update();
	virtual void Render(HDC hdc);
};

