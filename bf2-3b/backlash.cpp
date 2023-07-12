#include "Backlash.h"
#include "Player.h"
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
	BallAngle = (1 - BallAngle) + 0.5f;
	if (BallAngle > 1) BallAngle -= 1.0f;
	float rad = BallAngle * (float)M_PI * 2;
	MoveX = (int)(Speed * cosf(rad));
	MoveY = (int)(Speed * sinf(rad));
}

void Backlash::Draw()
{
	
}
