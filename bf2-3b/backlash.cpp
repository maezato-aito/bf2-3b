#include "Backlash.h"
#define e 0.800

Backlash::Backlash()
{

}

Backlash::~Backlash()
{
}

void Backlash::Update()
{
	v0 = sqrt(2.000 * g * y_max);
	for (i = 0; i < j; i++)
		v0 *= e;
}

void Backlash::Draw()
{
}
