#pragma once
#include "SingleTon.h"
#include <time.h>

// Ŭ����, �̱��� ���̽��� ���

// Ŭ�������� ��ȣ�ۿ��Ҽ� ���� ��찡 �����ϱ�.. ������ ȣ�� ������ �ٲܼ��ִ� �۾��� ���ټ� �־���Ѵ�.

class RandomFunction : public SingletonBase<RandomFunction>
{
public:
	RandomFunction()
	{
		//srand((unsigned)time(NULL));
		srand(GetTickCount());
	}
	~RandomFunction(){}

	inline int getInt(int num) { return rand() % num; }
	inline int getFromIntoTo(int fromNum, int toNum)
	{
		return rand() % (toNum - fromNum + 1) + fromNum;
	}
};