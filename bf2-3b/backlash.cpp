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
	//è„Ç…ìñÇΩÇ¡ÇΩÇ∆Ç´
	if (HitBox == 1) {
		/*boxX = boxX - 8;
		boxX2 = boxX - 8;*/
	}
	//â∫Ç…ìñÇΩÇ¡ÇΩÇ∆Ç´
	if (HitBox == 2) {

	}
	//âEÇ…ìñÇΩÇ¡ÇΩÇ∆Ç´
	if (HitBox == 3) {

	}
	//ç∂Ç…ìñÇΩÇ¡ÇΩÇ∆Ç´
	if (HitBox == 4) {

	}
}

void Backlash::Draw()
{
	
}