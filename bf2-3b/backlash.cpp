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
	
}

Backlash::~Backlash()
{

}

void Backlash::Update()
{
	//��ɓ��������Ƃ�
	if (HitBox == 1) {
		/*boxX = boxX - 8;
		boxX2 = boxX - 8;*/
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