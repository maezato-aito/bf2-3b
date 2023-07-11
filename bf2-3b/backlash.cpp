#include "Backlash.h"
#define _USE_MATH_DEFINES
#include <math.h>

Backlash::Backlash()
{
	// �X�s�[�h�ƃA���O���ɂ��ړ��ʌv�Z
	Speed = 5;
	BallAngle = 0.575f;
}

Backlash::~Backlash()
{

}

void Backlash::Update()
{

	float rad = BallAngle * (float)M_PI * 2;
	MoveX = (int)(Speed * cosf(rad));
	MoveY = (int)(Speed * sinf(rad));
}

void Backlash::Draw()
{
}
