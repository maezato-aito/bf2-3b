#include"fish.h"
#include"DxLib.h"

Fish::Fish()
{
	//�摜�̓ǂݍ���
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