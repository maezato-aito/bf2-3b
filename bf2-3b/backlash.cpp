#include "Backlash.h"
#include "Player.h"
#define _USE_MATH_DEFINES
#include <math.h>


Backlash::Backlash()
{
	Left = x1 + -x2;
	Right = -x1 + x2;
	North = y1 + -y2;
	South = -y1 + y2;
	HitBox = 0;
	// �X�s�[�h�ƃA���O���ɂ��ړ��ʌv�Z
	Speed = 5;
	BallAngle = 0.575f;
}

Backlash::~Backlash()
{

}

void Backlash::Update()
{
	//��ɓ��������Ƃ�
	if (HitBox == 1) {
		
	}
	//���ɓ��������Ƃ�
	if (HitBox == 2) {

	}
	//�E�ɓ��������Ƃ�
	if (HitBox == 3) {

	}
	//���ɓ��������Ƃ�
	if (HitBox == 4) {

	}
}

void Backlash::Draw()
{
	
}
