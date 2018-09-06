#pragma once

// 사용자 정의 빌드 구분

//#define _RENDER_TEST
//#define _CROP_TEST
#define _FRAME_TEST




// 메모리 해제 매크로
// Backbuffer
#define SAFE_DELETE(p)	{if(p) {delete(p);(p) = NULL;}}
#define SAFE_RELEASE(p)	{if(p) {(p)->Release(); (p) = NULL;}}

// 윈도우 사이즈 관련 매크로
#define WINSTYLE	WS_CAPTION | WS_SYSMENU

#define WINSIZEX	1000
#define WINSIZEY	800
#define WINSTARTX	100
#define WINSTARTY	100

// 싱글턴 객체 매크로
#define RAND		RandomFunction::getSingleton()
#define KEYMANAGER	KeyManager::getSingleton()