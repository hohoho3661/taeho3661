#include "stdafx.h"
#include "Backbuffer.h"


Backbuffer::Backbuffer() : _backBufferInfo(NULL)
{
}


Backbuffer::~Backbuffer()
{
}

bool Backbuffer::Init(int width, int height)
{
	if (_backBufferInfo != NULL)
		Release();

	HDC hdc = GetDC(_hWnd);
	_backBufferInfo = new BackbufferInfo;
	_backBufferInfo->hMemDC = CreateCompatibleDC(hdc);
	_backBufferInfo->hBit = (HBITMAP)CreateCompatibleBitmap(hdc, width, height);			// �׷���... ��ȯ�� ȭ�鸶�� �ѹ�����
	_backBufferInfo->hOldBit = (HBITMAP)SelectObject(_backBufferInfo->hMemDC, _backBufferInfo->hBit);
	_backBufferInfo->width = width;
	_backBufferInfo->height = height;

	if (_backBufferInfo->hBit == NULL)
	{
		Release();
		return false;
	}

	ReleaseDC(_hWnd, hdc);
	return false;
}

void Backbuffer::Release()
{
	if (_backBufferInfo)
	{
		SelectObject(_backBufferInfo->hMemDC, _backBufferInfo->hOldBit);
		DeleteObject(_backBufferInfo->hBit);
		DeleteDC(_backBufferInfo->hMemDC);

		SAFE_DELETE(_backBufferInfo);
	}
}



//  �������� ���� ��ǥ,,,, �ҽ��� ���� ��ǥ
void Backbuffer::Render(HDC hdc, int destX, int destY)
{
	// ����ۿ� ��µ� ������� ȭ������ ��Ӻ���
	BitBlt(hdc,									// ���簡 �Ǵ� DC
		destX,									// ���簡 �Ǵ� ��ġ
		destY,
		_backBufferInfo->width,					// ���簡 �Ǵ� ũ��
		_backBufferInfo->height,
		_backBufferInfo->hMemDC,				// ������ �ҽ��� �ִ� DC
		0,										// ������ �ҽ��� ���� ��ġ
		0,
		SRCCOPY);
}
