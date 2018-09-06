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

// 과제..
// 몬스터가 좌우로 왔다갔다 하도록.
// 플레이어 점프처리. 이중x 너무높지않게.. 몬스터를 넘을 정도.
// 부딪히면 충돌처리. 뒤로 튕겨나가게..
//
//
//
//
//
//
//
//