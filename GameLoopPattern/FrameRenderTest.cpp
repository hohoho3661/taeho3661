#include "stdafx.h"
#include "FrameRenderTest.h"
#include "Player.h"
#include "Monster.h"


FrameRenderTest::FrameRenderTest()
{
}


FrameRenderTest::~FrameRenderTest()
{
}

bool FrameRenderTest::Init()
{
	_background = new Image;
	_background->Init(TEXT("Image/background.bmp"), WINSIZEX, WINSIZEY);
	// Test
	// Test
	
	player = new Player;
	monster = new Monster;

	return true;
}

void FrameRenderTest::Release()
{
	SAFE_DELETE(_background);
	SAFE_DELETE(player);
	SAFE_DELETE(monster);
}

void FrameRenderTest::Update()
{
	player->Update();
	monster->Update();
}

void FrameRenderTest::Render(HDC hdc)
{
	_background->Render(hdc, 0, 0);
	player->Render(hdc);
	monster->Render(hdc);
}
