#include "Fish.h"
#include"DxLib.h"
#include"common.h"

Fish::Fish()
{
	fishX = 160;
	fishY = 300;
	LoadDivGraph("images/Enemy/Enemy_FishAnimation.png", 32, 8, 4, 64, 64, Fishimg);
}

Fish::~Fish()
{
}

void Fish::Update()
{
	return ;
}

void Fish::Draw()
{
	DrawGraph(fishX, fishY, Fishimg[3], TRUE);
}
