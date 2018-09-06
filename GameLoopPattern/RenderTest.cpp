#include "stdafx.h"
#include "RenderTest.h"



RenderTest::RenderTest()
{
}


RenderTest::~RenderTest()
{
}

bool RenderTest::Init()
{	
	GetClientRect(_hWnd, &rcClient);

	_background.x = 0;
	_background.image = new Image;
	_background.image->Init(TEXT("Image/background.bmp"), WINSIZEX, WINSIZEY);

	
	return true;
}

void RenderTest::Release()
{	
	SAFE_DELETE(_background.image);
}

void RenderTest::Update()
{
	_background.x += 5;
}

void RenderTest::Render(HDC hdc)
{
	//_background.image->Render(hdc, _background.x, 0);
	_background.image->LoopRender(hdc, &rcClient, _background.x, 0);
}
