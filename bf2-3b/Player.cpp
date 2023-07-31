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

	vx = 0.5;
	vy = 0.5;

	e = 0.8;		//�����W��

	LoadDivGraph("images/Player/Player_Animation.png",32,8,4,64,64,Playerimg);//�v���C���[�摜

	Speed = 0;
	playerLR = 0;

}
Player::~Player()
{

}
AbstractScene* Player::Update()
{
	GetJoypadAnalogInput(&InputX, &InputY, DX_INPUT_PAD1);

	//���D�̃{�b�N�X���
	bBoxX = playerX + 6;
	bBoxY = playerY + 12;
	bBoxX2 = bBoxX + 50;
	bBoxY2 = bBoxY + 22;

	//�v���C���[�̃{�b�N�X���
	pBoxX = playerX + 6;
	pBoxY = playerY + 32;
	pBoxX2 = pBoxX + 50;
	pBoxY2 = pBoxY + 32;

	//�d�͂̉��Z
	playerY += Gvy;

	if ((PAD_INPUT::OnPressed(XINPUT_BUTTON_B)))
	{
		if (bBoxY > 0)
		{
			Gvy = 3.0f;
			// ������Ă���
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
			// ������Ă���
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
	//�n�ʂɗ����Ă���Ƃ�
	if (//���̏�
		(S1_Landleft_X <= pBoxX2 && S1_Landleft_Width >= pBoxX &&
			S1_Landleft_Y <= pBoxY2) ||
		//�E�̏�
		(S1_Landright_X <= pBoxX2 && S1_Landright_Width >= pBoxX &&
			S1_Landright_Y <= pBoxY2) ||
		//�󒆂̏�
		(S1_Flooting_X <= pBoxX2 && S1_Flooting_Width >= pBoxX &&
			S1_Flooting_Y <= pBoxY2 && S1_Flooting_height >= pBoxY)
		)
	{

			if (playerX + 64 > 0)
			{
				//���ړ�
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
				//�E�ړ�
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
				//�����̍쐬
				Speed *= 0.94f;
			}
			Gvy = 0.0f;
			PlayerFlg = 0;
		}

		//�n�ʂɗ����Ă��Ȃ����
		else
		{
			if (playerX + 64 > 0)
			{
				//���ړ�
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
				//�E�ړ�
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
				//�����̍쐬
				Speed *= 0.99f;
			}
			Gvy = 0.98f;
			PlayerFlg = 1;
		}
	//�n�ʂɗ����Ă��邩
	///*if (pBoxY2 > S1_Landleft_Y)
	//{
	//	Gvy = 0.0f;
	//}
	//else
	//{
	//	Gvy = 0.98f;
	//}*/
	////�n�ʂɗ����Ă��Ȃ��Ƃ�
	////�E�n��
	//if ((S1_Landright_X-64 <= playerX && S1_Landright_Width >= playerX)&& S1_Landright_Y == playerY+64) {
	//	Gvy = 0;
	//	Speed *= 0.94f;
	//}
	//// �E�n�ʍ�����
	//else if (S1_Landright_X <= playerX && S1_Landright_Y < playerY+64) {
	//	/*vx -= vx*e;*/
	//	Gvy = 1;
	//	playerX = 420;
	//	playerY += Gvy;

	//}
	////���n��
	//else if ((S1_Landleft_X <= playerX+64 && S1_Landleft_Width >= playerX+20) && S1_Landleft_Y == playerY+64) {
	//	Gvy = 0;
	//	Speed *= 0.94f;
	//}
	//// ���n�ʉE����
	//else if (S1_Landleft_Width >= playerX+20 && S1_Landleft_Y < playerY+64) {
	//	Gvy = 1;
	//	playerX *= 0.8f;
	//	/*boxX2 = 210;*/
	//	playerY += Gvy;
	//	/*boxY2 += Gvy;*/
	//	
	//}
	////�󒆏�
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
	//	// �W�����v��������Ă��Ȃ�
	//	Gvy = 1;
	//	/*playerX += Gvy;*/
	//	playerY += Gvy;
	//}
	
	//�v���C���[�̉��ړ�
	playerX += Speed;


	if (playerX < -64)	// ������E
	{
		playerX = 576;

	}
	if (playerX > 620)	// �E���獶
	{
		playerX = -10;

	}
	return this;
}

void Player::Draw() const
{

	DrawFormatString(0, 0, 0xffffff,"%d",InputX, TRUE);
	DrawFormatString(0, 20, 0xffffff, "Speed:%5.2f", Speed, TRUE);
	DrawFormatString(0, 40, 0xffffff, "���E:%d�@1:���@2:�E", playerLR, TRUE);
	DrawFormatString(0, 60, 0xffffff, "%f", Gvy, TRUE);
	DrawFormatString(0, 80, 0xffffff, "�v���C���[���W X0:%d Y0:%d X1:%d Y1:%d",pBoxX,pBoxY,pBoxX2,pBoxY2, TRUE);

	DrawFormatString(0, 100, 0xffffff, "�v���C���[�̏�� %d�@0:�n�ʁ@1:��", PlayerFlg, TRUE);

	DrawBox(pBoxX, pBoxY, pBoxX2, pBoxY2, 0xff2255, FALSE);//�v���C���[��box
	DrawBox(bBoxX, bBoxY, bBoxX2, bBoxY2, 0xff2255, FALSE);//���D��box
	DrawGraph(playerX, playerY, Playerimg[1], TRUE);
	DrawGraph(640 + playerX, playerY, Playerimg[0], TRUE);
	DrawGraph(playerX - 640, playerY, Playerimg[0], TRUE);

}
