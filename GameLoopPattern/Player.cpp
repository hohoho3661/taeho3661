#include "stdafx.h"
#include "Player.h"



Player::Player()
{
	_siva = new Image;
	_siva->Init(TEXT("SpriteImage/시바달리기.bmp"), 440, 108, 8, 2, true, RGB(255, 0, 255)); // 파일이름... 이미지전체 x,y크기 ... 그이미지의 갯수 x값, y값.
	_siva->SetX(WINSIZEX / 2);
	_siva->SetY(WINSIZEY - 100);
}


Player::~Player()
{
	SAFE_DELETE(_siva);
}

void Player::Update()
{
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_siva->SetX(_siva->GetX() - 3);
		_dirChange = true;
		_siva->SetFrameY(1);
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_siva->SetX(_siva->GetX() + 3);
		_dirChange = false;
		_siva->SetFrameY(0);
	}


	_nCount++;

	if (_nCount % 10 == 0) // 1/100초마다 하나씩 그려짐. (원래는 1/1000초인데.. 10당 1개니까) ..... 프레임 skiping.
	{
		if (_dirChange)
		{
			if (_iIndex <= 0)
				_iIndex = 5;

			_iIndex--;

			_siva->SetFrameX(_iIndex);
		}
		else
		{
			if (_iIndex >= _siva->GetMaxFrameX())
				_iIndex = 2;

			_iIndex++;

			_siva->SetFrameX(_iIndex);
		}

		_nCount = 0;
	}

}

void Player::Render(HDC hdc)
{
	_siva->FrameRender(hdc, _siva->GetX(), _siva->GetY(),
		_siva->GetFrameX(), _siva->GetFrameY());
}
