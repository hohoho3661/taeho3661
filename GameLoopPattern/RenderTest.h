#pragma once
#include "GameNode.h"

struct LoopObj
{
	int x;
	Image* image;
};


class RenderTest : public GameNode
{
	RECT	rcClient;
	LoopObj _background;

public:
	RenderTest();
	virtual ~RenderTest();


	virtual bool Init();
	virtual void Release();
	virtual void Update();
	virtual void Render(HDC hdc);
};

