#include"DxLib.h"
#include"Player.h"
#include"PadInput.h"
#include"common.h"

 int Player::pBoxX;
 int Player::pBoxY;
 int Player::pBoxX2;
 int Player::pBoxY2;

 int Player::bBoxX;
 int Player::bBoxY;
 int Player::bBoxX2;
 int Player::bBoxY2;

Player::Player()
{
	Gvy = 0;

	playerX = 100;
	playerY = 340;

	PlayerFlg = 1;
	HitFlg = 1;		
	vx = 0.5;
	vy = 0.5;

	e = 0.8;		//反発係数

	LoadDivGraph("images/Player/Player_Animation.png",32,8,4,64,64,Playerimg);//プレイヤー画像

	Speed = 0;
	playerLR = 0;

}
Player::~Player()
{

}
AbstractScene* Player::Update()
{
	GetJoypadAnalogInput(&InputX, &InputY, DX_INPUT_PAD1);

	//風船のボックス情報
	bBoxX = playerX + 6;
	bBoxY = playerY + 12;
	bBoxX2 = bBoxX + 50;
	bBoxY2 = bBoxY + 22;

	//プレイヤーのボックス情報
	pBoxX = playerX + 6;
	pBoxY = playerY + 32;
	pBoxX2 = pBoxX + 50;
	pBoxY2 = pBoxY + 32;

	//重力の加算
	playerY += Gvy;

	if ((PAD_INPUT::OnPressed(XINPUT_BUTTON_B)))
	{
		if (bBoxY > 0)
		{
			Gvy = 3.0f;
			// 押されている
			playerY -= Gvy;
			/*boxY2 -= Gvy;*/
		}
		else if (bBoxY < 0)
		{
			/*vy = -vy * e;
			playerY *= vy;*/
		}
	}
	else if ((PAD_INPUT::OnButton(XINPUT_BUTTON_A)))
	{
		if (bBoxY > 0)
		{
			Gvy = 20.0f;
			// 押されている
			playerY -= Gvy;
			/*boxY2 -= Gvy;*/
		}
		else if (playerY == 0) 
		{
			/*

			vy = -vy * e;
			playerY *= vy;

			*/
		}
	}
	//地面に立っているとか
	if (//左の床
		(S1_Landleft_X <= pBoxX2 && S1_Landleft_Width >= pBoxX &&
			S1_Landleft_Y <= pBoxY2) ||
		//右の床
		(S1_Landright_X <= pBoxX2 && S1_Landright_Width >= pBoxX &&
			S1_Landright_Y <= pBoxY2) ||
		//空中の床
		(S1_Flooting_X <= pBoxX2 && S1_Flooting_Width >= pBoxX &&
			S1_Flooting_Y <= pBoxY2 && S1_Flooting_height >= pBoxY)
		)
	{

			if (playerX + 64 > 0)
			{
				//左移動
				if (InputX < -1)
				{
					if (Speed > -3)
					{
						Speed -= 0.1f;
					}

					playerLR = 1;
					/*playerY += 6;*/
				}
			}

			if (playerX < 640)
			{
				//右移動
				if (InputX > 1)
				{
					if (Speed < 3)
					{
						Speed += 0.1f;
					}
					playerLR = 2;
					/*playerY += 6;*/
				}
			}

			if (InputX == 0)
			{
				//慣性の作成
				Speed *= 0.94f;
			}
			Gvy = 0.0f;
			PlayerFlg = 0;
			HitFlg = 0;
		}

		//地面に立っていなければ
		else
		{
			if (playerX + 64 > 0)
			{
				//左移動
				if (InputX < -1)
				{
					if (Speed > -3)
					{
						Speed -= 0.1f;
					}

					playerLR = 1;
					/*playerY += 6;*/
				}
			}

			if (playerX < 640)
			{
				//右移動
				if (InputX > 1)
				{
					if (Speed < 3)
					{
						Speed += 0.1f;
					}
					playerLR = 2;
					/*playerY += 6;*/
				}
			}

			if (InputX == 0)
			{
				//慣性の作成
				Speed *= 0.99f;
			}
			Gvy = 0.98f;
			PlayerFlg = 1;
			HitFlg = 0;
		}
	//地面左壁
	if (S1_Landleft_X <= pBoxX2 &&  S1_Landleft_Width >= pBoxX && S1_Landleft_height >= pBoxY
		&& S1_Landleft_Y+1 < pBoxY2) {
		HitFlg = 1;
	}
	// 地面右壁
	if (S1_Landright_X <= pBoxX2 && S1_Landright_Width >= pBoxX && S1_Landright_height >= pBoxY &&
		S1_Landright_Y + 1 < pBoxY2) {
		HitFlg = 2;
	}
	// 反発
	// 左側に触れたとき
	if (HitFlg == 1 && Speed < -0.5) {
		Speed *= -0.8;
	}
	// 右側に触れたとき
	if (HitFlg == 2 && Speed > 0.5) {
		Speed *= -0.8;
	}
	if (HitFlg == 1 || HitFlg == 2 && Speed > -0.5 && Speed < 0.5) {
		Gvy = 0.98f;
		Speed *= 0.8;
	}
	//地面に立っているか
	///*if (pBoxY2 > S1_Landleft_Y)
	//{
	//	Gvy = 0.0f;
	//}
	//else
	//{
	//	Gvy = 0.98f;
	//}*/
	////地面に立っていないとき
	////右地面
	//if ((S1_Landright_X-64 <= playerX && S1_Landright_Width >= playerX)&& S1_Landright_Y == playerY+64) {
	//	Gvy = 0;
	//	Speed *= 0.94f;
	//}
	//// 右地面左側面
	//else if (S1_Landright_X <= playerX && S1_Landright_Y < playerY+64) {
	//	/*vx -= vx*e;*/
	//	Gvy = 1;
	//	playerX = 420;
	//	playerY += Gvy;

	//}
	////左地面
	//else if ((S1_Landleft_X <= playerX+64 && S1_Landleft_Width >= playerX+20) && S1_Landleft_Y == playerY+64) {
	//	Gvy = 0;
	//	Speed *= 0.94f;
	//}
	//// 左地面右側面
	//else if (S1_Landleft_Width >= playerX+20 && S1_Landleft_Y < playerY+64) {
	//	Gvy = 1;
	//	playerX *= 0.8f;
	//	/*boxX2 = 210;*/
	//	playerY += Gvy;
	//	/*boxY2 += Gvy;*/
	//	
	//}
	////空中床
	//else if ((S1_Flooting_X <= playerX && S1_Flooting_Width >= playerX+64) && S1_Flooting_Y == playerY+64) {
	//	Gvy = 0;
	//	Speed *= 0.94f;
	//}

	//else if ((S1_Flooting_X <= playerX && S1_Flooting_Width >= playerX + 64) && S1_Flooting_height == playerY+64){
	//	Gvy = -5;
	//	playerY += Gvy;
	//}
	//else
	//{
	//	// ジャンプが押されていない
	//	Gvy = 1;
	//	/*playerX += Gvy;*/
	//	playerY += Gvy;
	//}
	
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
	DrawFormatString(0, 20, 0xffffff, "Speed:%5.2f", Speed, TRUE);
	DrawFormatString(0, 40, 0xffffff, "左右:%d　1:左　2:右", playerLR, TRUE);
	DrawFormatString(0, 60, 0xffffff, "%f", Gvy, TRUE);
	DrawFormatString(0, 80, 0xffffff, "プレイヤー座標 X0:%d Y0:%d X1:%d Y1:%d",pBoxX,pBoxY,pBoxX2,pBoxY2, TRUE);

	DrawFormatString(0, 100, 0xffffff, "プレイヤーの状態 %d　0:地面　1:空中", PlayerFlg, TRUE);
	DrawFormatString(0, 130, 0xffffff, "プレイヤーの状態 %d　0:触れていない　1:左側に触れている　2:右側に触れている　", HitFlg, TRUE);

	DrawBox(pBoxX, pBoxY, pBoxX2, pBoxY2, 0xff2255, FALSE);//プレイヤーのbox
	DrawBox(bBoxX, bBoxY, bBoxX2, bBoxY2, 0xff2255, FALSE);//風船のbox
	DrawGraph(playerX, playerY, Playerimg[1], TRUE);
	DrawGraph(640 + playerX, playerY, Playerimg[0], TRUE);
	DrawGraph(playerX - 640, playerY, Playerimg[0], TRUE);

}
