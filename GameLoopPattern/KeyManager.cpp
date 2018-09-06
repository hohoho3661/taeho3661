#include "stdafx.h"
#include "KeyManager.h"



KeyManager::KeyManager()
{
}


KeyManager::~KeyManager()
{
}

bool KeyManager::Init()
{
	this->getKeyUp().reset();
	this->getKeyDown().reset();

	return true;
}

void KeyManager::Release()
{
}

bool KeyManager::isOnceKeyDown(int _key)	// ���� Ű�� ���Ǵ����� �˰������. (�������´� ���ɻ簡 �ƴ�)
{
	if (GetAsyncKeyState(_key) & 0x8000)
	{
		if (!this->getKeyDown()[_key])
		{
			this->setKeyDown(_key, true);
			return true;
		}
	}
	else
		this->setKeyDown(_key, false);

	return false;
}

bool KeyManager::isOnceKeyUp(int _key)
{
	if (GetAsyncKeyState(_key) & 0x8000)
		this->setKeyUp(_key, true);
	else
	{
		if (this->getKeyUp()[_key])
		{
			this->setKeyUp(_key, false);
			return true;
		}
	}

	return false;
}

bool KeyManager::isStayKeyDown(int _key) // ���� ��� �������ִ°�� true, �ƴϸ� false
{
	if (GetAsyncKeyState(_key) & 0x8000)
		return true;

	return false;
}

bool KeyManager::isToggleKey(int _key) // �ѹ� ������ on, �ٽô����� false     ex) Caps Lock�������.
{
	if (GetKeyState(_key) & 0x0001)
		return true;

	return false;
}
