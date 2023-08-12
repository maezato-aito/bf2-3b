#include "GameOver.h"
#include "DxLib.h"
#include "common.h"

GameOver::GameOver()
{
	
}

GameOver::~GameOver()
{

}

void GameOver::Update()
{
	
}

void GameOver::Draw()
{
	if (Player::PlayerFlg == 0) {

		DrawString(270, 210, "GAME OVER", 0xffffff);
	}
	
}