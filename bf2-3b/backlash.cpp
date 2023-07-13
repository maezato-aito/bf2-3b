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
	// スピードとアングルによる移動量計算
	Speed = 5;
	BallAngle = 0.575f;
}

Backlash::~Backlash()
{

}

void Backlash::Update()
{
	//上に当たったとき
	if (HitBox == 1) {
		
	}
	//下に当たったとき
	if (HitBox == 2) {

	}
	//右に当たったとき
	if (HitBox == 3) {

	}
	//左に当たったとき
	if (HitBox == 4) {

	}
}

void Backlash::Draw()
{
	
}
