#include"DxLib.h"
#include"Player.h"
#include"PadInput.h"
#include"common.h"


int Gvy = 0;

Player::Player()
{
	playerX = 100;
	playerY = 340;
	vx = 0.5;
	vy = 0.5;
	e = 0.8;		//反発係数
	LoadDivGraph("images/Player/Player_Animation.png",32,8,4,64,64,Playerimg);
	Speed = 0;
	playerLR = 0;

}
Player::~Player()
{

}
AbstractScene* Player::Update()
{
	pBoxX = playerX + 6;
	pBoxY = playerY + 12;
	pBoxX2 = pBoxX + 50;
	pBoxY2 = pBoxY + 52;

	if ((PAD_INPUT::OnPressed(XINPUT_BUTTON_B)))
	{
		if (playerY > 0) 
		{
			Gvy = 3;
			// 押されている
			playerY -= Gvy;
			/*boxY2 -= Gvy;*/
		}
		else if (playerY < 0) {
			vy = -vy * e;
			playerY *= vy;
		}
	}
	else if ((PAD_INPUT::OnButton(XINPUT_BUTTON_A)))
	{
		if (pBoxY > 0)
		{
			Gvy = 20;
			// 押されている
			playerY -= Gvy;
			/*boxY2 -= Gvy;*/
		}
		else if (playerY == 0) {
			vy = -vy * e;
			playerY *= vy;
		}
		
		
	}

	
	//地面に立っていないとき
	//右地面
	if ((S1_Landright_X-64 <= playerX && S1_Landright_Width >= playerX)&& S1_Landright_Y == playerY+64) {
		Gvy = 0;
		Speed *= 0.94f;
	}
	// 右地面左側面
	else if (S1_Landright_X <= playerX && S1_Landright_Y < playerY+64) {
		/*vx -= vx*e;*/
		Gvy = 1;
		playerX = 420;
		playerY += Gvy;

	}
	//左地面
	else if ((S1_Landleft_X <= playerX+64 && S1_Landleft_Width >= playerX+20) && S1_Landleft_Y == playerY+64) {
		Gvy = 0;
		Speed *= 0.94f;
	}
	// 左地面右側面
	else if (S1_Landleft_Width >= playerX+20 && S1_Landleft_Y < playerY+64) {
		Gvy = 1;
		playerX *= 0.8f;
		/*boxX2 = 210;*/
		playerY += Gvy;
		/*boxY2 += Gvy;*/
		
	}
	//空中床
	else if ((S1_Flooting_X <= playerX && S1_Flooting_Width >= playerX+64) && S1_Flooting_Y == playerY+64) {
		Gvy = 0;
		Speed *= 0.94f;
	}

	else if ((S1_Flooting_X <= playerX && S1_Flooting_Width >= playerX + 64) && S1_Flooting_height == playerY+64){
		Gvy = -5;
		playerY += Gvy;
	}
	else
	{
		// ジャンプが押されていない
		Gvy = 1;
		/*playerX += Gvy;*/
		playerY += Gvy;
	}

	
	GetJoypadAnalogInput(&InputX, &InputY, DX_INPUT_PAD1);
	if (playerX+64 > 0) {
		//左移動
		if (InputX < -1)
		{
			if (Speed > -3) {
				Speed -= 0.1f;
			}

			playerLR = 1;
			/*playerY += 6;*/
		}
	}
		
	if (playerX < 640) {
		//右移動
		if (InputX > 1)
		{
			if (Speed < 3) {
				Speed += 0.1f;
			}
			playerLR = 2;
			/*playerY += 6;*/
		}
	}

	if (InputX == 0) {
		//慣性の作成
		Speed *= 0.99f;
	}
	
	//プレイヤーの横移動
	playerX += Speed;


	if (playerX < -64)	// 左から右
	{
		playerX = 576;

	}
	if (playerX > 620)	// 右から左
	{
		playerX = -10;

	}
	return this;
}

void Player::Draw() const
{
	DrawFormatString(0, 0, 0xffffff,"%d",InputX, TRUE);
	DrawFormatString(0, 40, 0xffffff, "Speed:%5.2f", Speed, TRUE);
	DrawFormatString(0, 80, 0xffffff, "左右:%d　1:左　2:右", playerLR, TRUE);

	/*DrawBox(boxX, boxY,boxX2, boxY2+5, 0xffffff, TRUE);*/
	DrawBox(pBoxX, pBoxY, pBoxX2, pBoxY2, 0xff2255, FALSE);
	DrawGraph(playerX, playerY, Playerimg[1], TRUE);
	DrawGraph(640 + playerX, playerY, Playerimg[0], TRUE);
	DrawGraph(playerX - 640, playerY, Playerimg[0], TRUE);
}
