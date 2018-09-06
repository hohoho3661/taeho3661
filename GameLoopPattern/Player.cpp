#include "stdafx.h"
#include "Player.h"



Player::Player()
{
	_siva = new Image;
	_siva->Init(TEXT("SpriteImage/�ùٴ޸���.bmp"), 440, 108, 8, 2, true, RGB(255, 0, 255)); // �����̸�... �̹�����ü x,yũ�� ... ���̹����� ���� x��, y��.
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

	if (_nCount % 10 == 0) // 1/100�ʸ��� �ϳ��� �׷���. (������ 1/1000���ε�.. 10�� 1���ϱ�) ..... ������ skiping.
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
