#include"DxLib.h"
#include"Player.h"
#include"PadInput.h"
#include"common.h"
#include"Enemy.h"

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
	Gvy = 0.98;
	gCount = 0;

	playerX = 100;
	playerY = 240;

	PlayerFlg = 1;
	HitFlg = 1;		
	vx = 0.5;
	vy = 0.5;

	e = 0.8;		//�����W��

	LoadDivGraph("images/Player/Player_Animation.png",32,8,4,64,64,Playerimg);//�v���C���[�摜
	AnimCount = 0;

	Image = 0;
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
	//�G�̃{�b�N�X
	eBoxX = Enemy::eBoxX;
	eBoxY = Enemy::eBoxY;
	eBoxX2 = Enemy::eBoxX2;
	eBoxY2 = Enemy::eBoxY2;
	// �G�̕��D�̃{�b�N�X
	ebBoxX = Enemy::ebBoxX;
	ebBoxY = Enemy::ebBoxY;
	ebBoxX2 = Enemy::ebBoxX2;
	ebBoxY2 = Enemy::ebBoxY2;


		if (1 < Gvy)
		{
			Gvy = 1;
		}
		//�d�͂̉��Z
		playerY += Gvy;
	

	if ((PAD_INPUT::OnPressed(XINPUT_BUTTON_B)) || (PAD_INPUT::OnButton(XINPUT_BUTTON_A)))
	{
		if (bBoxY >= 0)
		{
			pUP();
		}
	}
	if (++AnimCount < 400.0f)
	{
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
						Speed -= 0.016f;
					}

						if (0 <= AnimCount)
						{
							Image = 8;
						}
						if (5 <= AnimCount)
						{
							Image = 9;
						}
						if (10 <= AnimCount)
						{
							Image = 10;
						}
						if (14 <= AnimCount)
						{
							AnimCount = 0;
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
						Speed += 0.016f;
					}

					if (0 <= AnimCount)
					{
						Image = 8;
					}
					if (5 <= AnimCount)
					{
						Image = 9;
					}
					if (10 <= AnimCount)
					{
						Image = 10;
					}
					if (14 <= AnimCount)
					{
						AnimCount = 0;
					}
					playerLR = 2;
				}
			}

			if (InputX == 0)
			{
				//�����̍쐬
				Speed = 0.0f;
				

				/*�ҋ@���A�j���[�V����*/
				if (0 <= AnimCount)
				{
					Image = 1;
				}
				if (100 <= AnimCount)
				{
					Image = 0;
				}
				if (200 <= AnimCount)
				{
					Image = 1;
				}
				if (300 <= AnimCount)
				{
					Image = 2;
				}
				if (399 <= AnimCount)
				{
					AnimCount = 0;
				}
			}
			Gvy = 0.0f;
			PlayerFlg = 0;
			HitFlg = 0;
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
						Speed -= 0.016f;
					}

					if (0 <= AnimCount)
					{
						Image = 17;
					}
					if (5 <= AnimCount)
					{
						Image = 18;
					}
					if (10 <= AnimCount)
					{
						Image = 19;
					}
					if (15 <= AnimCount)
					{
						Image = 18;
					}
					if (19 <= AnimCount)
					{
						AnimCount = 0;
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
						Speed += 0.016f;
					}

					if (0 <= AnimCount)
					{
						Image = 17;
					}
					if (5 <= AnimCount)
					{
						Image = 18;
					}
					if (10 <= AnimCount)
					{
						Image = 19;
					}
					if (15 <= AnimCount)
					{
						Image = 18;
					}
					if (19 <= AnimCount)
					{
						AnimCount = 0;
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
			Gvy += 0.1f;
			PlayerFlg = 1;
			HitFlg = 0;
		}
		//���n�ʕ�
		if (S1_Landleft_X <= pBoxX2 && S1_Landleft_Width >= pBoxX &&
			S1_Landleft_height >= bBoxY && S1_Landleft_Y + 1 < pBoxY2) {
			HitFlg = 1;
		}
		// �E�n�ʕ�
		if (S1_Landright_X <= pBoxX2 && S1_Landright_Width >= pBoxX &&
			S1_Landright_height >= bBoxY && S1_Landright_Y + 1 < pBoxY2) {
			HitFlg = 2;
		}
		//�󒆏�����
		if (S1_Flooting_X <= pBoxX2 && S1_Flooting_Width >= pBoxX &&
			S1_Flooting_Y + 1 < pBoxY2 && S1_Flooting_height - 1 >= bBoxY && Speed > 0.5) {
			HitFlg = 2;
		}
		// �󒆏��E��
		if (S1_Flooting_X <= pBoxX2 && S1_Flooting_Width >= pBoxX &&
			S1_Flooting_Y + 1 < pBoxY2 && S1_Flooting_height - 1 >= bBoxY && Speed < -0.5) {
			HitFlg = 1;
		}
		if (S1_Flooting_X <= bBoxX2 && S1_Flooting_Width >= bBoxX &&
			S1_Flooting_height == bBoxY) {
			Gvy *= 0.8f;
		}

		// �G�̍����ɓ��������Ƃ�
		//// �G�̔�������ɓ��������Ƃ�
		//if (pBoxX2 == ebBoxX && pBoxY + 7 <= eBoxY + 7 && pBoxY2 <= ebBoxY && playerLR == 2) {
		//	HitFlg = 2;
		//}
		////// �G�̔�����艺�ɓ��������Ƃ�
		////if (pBoxX2 == ebBoxX && pBoxY + 7 >= eBoxY + 7 && pBoxY2 >= ebBoxY && playerLR == 2) {
		////	HitFlg = 2;
		////}
		//// �G�ƍ�����������
		//if (pBoxX2 == ebBoxX && bBoxY == ebBoxY && pBoxY2 == eBoxY2 && playerLR == 2) {
		//	HitFlg = 2;
		//}
		//// �G�̉E���ɓ��������Ƃ�
		//// �G�̔�������ɓ��������Ƃ�
		//if (pBoxX == ebBoxX2 && pBoxY + 7 <= eBoxY + 7 && pBoxY2 <= ebBoxY && playerLR == 1) {
		//	HitFlg = 1;
		//}
		//// �G�̔�����艺�ɓ��������Ƃ�
		//if (pBoxX == ebBoxX2 && pBoxY + 7 >= eBoxY + 7 && bBoxY >= eBoxY2 && playerLR == 1) {
		//	HitFlg = 1;
		//}
		//// �G�ƍ�����������
		//if (pBoxX == ebBoxX2 && bBoxY == ebBoxY && pBoxY2 == eBoxY2) {
		//	HitFlg = 1;
		//}
		// ����
		// �����ɐG�ꂽ�Ƃ�
		if (HitFlg == 1 && Speed < -0.5) {
			Speed *= -0.8;
		}
		// �E���ɐG�ꂽ�Ƃ�
		if (HitFlg == 2 && Speed > 0.5) {
			Speed *= -0.8;
		}
		/*if (HitFlg == 1 || HitFlg == 2 && Speed > -0.5 && Speed < 0.5) {
			Gvy = 0.98f;
			Speed *= 0.8;
		}*/


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
	}
	return this;
}

void Player::Draw() const
{
#if _DEBUG
	DrawFormatString(0, 0, 0xffffff,"%d",InputX, TRUE);
	DrawFormatString(0, 20, 0xffffff, "Speed:%5.2f", Speed, TRUE);
	DrawFormatString(0, 40, 0xffffff, "���E:%d�@1:���@2:�E", playerLR, TRUE);
	DrawFormatString(0, 60, 0xffffff, "%f", Gvy, TRUE);
	DrawFormatString(0, 80, 0xffffff, "�v���C���[���W X0:%d Y0:%d X1:%d Y1:%d",pBoxX,pBoxY,pBoxX2,pBoxY2, TRUE);

	DrawFormatString(0, 100, 0xffffff, "�v���C���[�̏�� %d�@0:�n�ʁ@1:��", PlayerFlg, TRUE);
	DrawFormatString(0, 130, 0xffffff, "�v���C���[�̏�� %d�@0:�G��Ă��Ȃ��@1:�����ɐG��Ă���@2:�E���ɐG��Ă���@", HitFlg, TRUE);
	DrawFormatString(0, 160, 0xffffff, "%d", AnimCount, TRUE);

	DrawBox(pBoxX, pBoxY, pBoxX2, pBoxY2, 0xff2255, FALSE);//�v���C���[��box
	DrawBox(bBoxX, bBoxY, bBoxX2, bBoxY2, 0xff2255, FALSE);//���D��box
#endif _DEBUG

	//�����ŕ`��
	//������
	if (playerLR == 1) 
	{
		DrawGraph(playerX, playerY, Playerimg[Image], TRUE);
	}
	//�E����
	else
	{
		DrawTurnGraph(playerX, playerY, Playerimg[Image], TRUE);
	}
	
	DrawGraph(640 + playerX, playerY, Playerimg[0], TRUE);
	DrawGraph(playerX - 640, playerY, Playerimg[0], TRUE);

}

void Player::pUP()
{
	Gvy = -2.0f;
}