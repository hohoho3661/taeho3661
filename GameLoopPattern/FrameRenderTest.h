#pragma once

class Player;
class Monster;

class FrameRenderTest : public GameNode
{
	Image*	_background;

	//Image*	_siva;
	//Image*	_monster;
	
	Player*		player;
	Monster*	monster;

public:
	FrameRenderTest();
	virtual ~FrameRenderTest();


	virtual bool Init();
	virtual void Release();
	virtual void Update();
	virtual void Render(HDC hdc);
};

// ����..
// ���Ͱ� �¿�� �Դٰ��� �ϵ���.
// �÷��̾� ����ó��. ����x �ʹ������ʰ�.. ���͸� ���� ����.
// �ε����� �浹ó��. �ڷ� ƨ�ܳ�����..
//
//
//
//
//
//
//
//