#include"fish.h"
#include"DxLib.h"

Fish::Fish()
{
	//‰æ‘œ‚Ì“Ç‚İ‚İ
	LoadDivGraph("images/Enemy/Enemy_FishAnimation.png", 10, 5, 2, 64, 64, fishImg);
}

Fish::~Fish()
{

}

void Fish::Update()
{

}

void Fish::Draw()
{
	DrawExtendGraph(270, 400, 320, 450, fishImg[2], TRUE);
	
}