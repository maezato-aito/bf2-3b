#include "GameOver.h"
#include "DxLib.h"
#include "common.h"

GameOver::GameOver()
{
	SEGameOver = LoadSoundMem("sound/SE_GameOver.wav");
}

GameOver::~GameOver()
{

}

void GameOver::Update()
{
	// ゲームオーバーのSE
	if (Player::PlayerFlg == 0 && Player::Life == 0) {
		
	}
}

void GameOver::Draw()
{
	if (Player::PlayerFlg == 0 && Player::Life == 0 ) {

		DrawString(270, 210, "GAME OVER", 0xffffff);
	}
	
}