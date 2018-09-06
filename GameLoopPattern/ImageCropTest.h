#pragma once

class ImageCropTest : public GameNode
{
	Image*	_background;
	int		_offsetX, _offsetY;

public:
	ImageCropTest();
	virtual ~ImageCropTest();


	virtual bool Init();
	virtual void Release();
	virtual void Update();
	virtual void Render(HDC hdc);
};

