#include "stdafx.h"
#include "Monster.h"



Monster::Monster()
{
	_monster = new Image;
	_monster->Init(TEXT("SpriteImage/Monster.bmp"), 358, 632, 2, 4, true, RGB(255, 0, 255)); // 파일이름... 이미지전체 x,y크기 ... 그이미지의 갯수 x값, y값.
	_monster->SetX(WINSIZEX / 3);
	_monster->SetY(WINSIZEY - 200);
}


Monster::~Monster()
{
	SAFE_DELETE(_monster);
}

void Monster::Update()
{
	if (KEYMANAGER->isStayKeyDown(0x41))
	{
		_monster->SetX(_monster->GetX() - 3);
		_dirChange = true;
		_monster->SetFrameX(0);
	}
	if (KEYMANAGER->isStayKeyDown(0x44))
	{
		_monster->SetX(_monster->GetX() + 3);
		_dirChange = false;
		_monster->SetFrameX(1);
	}

	_nCount++;

	if (_nCount % 10 == 0) // 1/100초마다 하나씩 그려짐. (원래는 1/1000초인데.. 10당 1개니까) ..... 프레임 skiping.
	{
		if (_dirChange)
		{
			if (_iIndex <= 0)
				_iIndex = 4;

			_iIndex--;

			_monster->SetFrameY(_iIndex);
		}
		else
		{
			if (_iIndex >= _monster->GetMaxFrameY())
				_iIndex = 0;

			_iIndex++;

			_monster->SetFrameY(_iIndex);
		}

		_nCount = 0;
	}
}

void Monster::Render(HDC hdc)
{
	_monster->FrameRender(hdc, _monster->GetX(), _monster->GetY(),
		_monster->GetFrameX(), _monster->GetFrameY());
}
