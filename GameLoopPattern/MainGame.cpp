#include "stdafx.h"
#include "MainGame.h"

#include "ImageCropTest.h"
#include "RenderTest.h"
#include "FrameRenderTest.h"

// ���������� ����ؼ� 
// �̹��� �ϳ���.


MainGame::MainGame()
{
}


MainGame::~MainGame()
{
}



bool MainGame::Init() // �ʱ�ȭ
{
	GameNode::Init();

	//===================================

#if defined(_RENDER_TEST)
	renderTest = new RenderTest;
	assert(renderTest != NULL);
	renderTest->Init();
#elif defined(_CROP_TEST)
	cropTest = new ImageCropTest;
	assert(cropTest != NULL);
	cropTest->Init();

#elif defined(_FRAME_TEST)
	frameTest = new FrameRenderTest;
	assert(frameTest != NULL);
	frameTest->Init();
#endif //


	//===================================

	return true;
}

void MainGame::Release() // ����
{
	GameNode::Release();
	//==================================
#if defined(_RENDER_TEST)
	renderTest->Release();
#elif defined(_CROP_TEST)
	cropTest->Release();
#elif defined(_FRAME_TEST)
	frameTest->Release();
#endif //


	//==================================
}

void MainGame::Update() // ����
{
	GameNode::Update();
	//==================================
#if defined(_RENDER_TEST)
	renderTest->Update();
#elif defined(_CROP_TEST)
	cropTest->Update();
#elif defined(_FRAME_TEST)
	frameTest->Update();
#endif //
	//==================================

}

void MainGame::Render(HDC hdc) // �׸��� ( ȭ�� ��� ) // �������۾��� ����ۿ� �����Ӵ����� 1/10�ʸ��� �ѹ��� ȭ�鿡 �ѷ���
{
	//GameNode::Render(hdc);

	HDC	backDC = (this->GetBackBuffer())->GetMemDC();
	PatBlt(backDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//============================
	// ����۾��� ���� �ȿ��� �۾�.
#if defined(_RENDER_TEST)
	renderTest->Render(backDC);
#elif defined(_CROP_TEST)
	cropTest->Render(backDC);
#elif defined(_FRAME_TEST)
	frameTest->Render(backDC);
#endif //
	//============================
	this->GetBackBuffer()->Render(hdc, 0, 0);
}


