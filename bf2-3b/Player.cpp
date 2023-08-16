#include"DxLib.h"
#include"Player.h"
#include"PadInput.h"
#include"common.h"
#include"Enemy.h"
#include"fish.h"

 int Player::pBoxX;
 int Player::pBoxY;
 int Player::pBoxX2;
 int Player::pBoxY2;

 int Player::bBoxX;
 int Player::bBoxY;
 int Player::bBoxX2;
 int Player::bBoxY2;
 int Player::PlayerFlg;
 int Player::Life;
 float Player::playerX;
 float Player::playerY;
 int Player::Time;

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

	UpFlg = 0;
	UpNum = 0;
	buttonC = 0;

	Life = 2;

	

	Time = 0; // �ҋ@����

	a = 0;
}
Player::~Player()
{

}
AbstractScene* Player::Update()
{
	GetJoypadAnalogInput(&InputX, &InputY, DX_INPUT_PAD1);

	if (PlayerFlg == 1 || PlayerFlg == 2 || PlayerFlg == 3) {
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


		UpFlg = 0;

		if (2 <= Gvy)
		{
			Gvy = 2;
		}
		//�d�͂̉��Z
		playerY += a;

		a = Gvy - UpNum;

		if ((0.1 > Gvy - UpNum) && 45 > bBoxY)
		{

		}
		if ((PAD_INPUT::OnPressed(XINPUT_BUTTON_B)) || (PAD_INPUT::OnButton(XINPUT_BUTTON_A)))
		{
			if (bBoxY > 0)
			{

				UpNum = 3;
				UpFlg = 1;
			}
			else
			{
				UpNum = 0;
			}
		}
		else
		{
			if (0.01 < UpNum)
			{
				UpNum -= 0.1;
			}

		}
		if (++AnimCount < 400.0f)
		{
			//�n�ʂɗ����Ă���Ƃ�
			if (//���̏�
				(S1_Landleft_X-2 <= pBoxX2 && S1_Landleft_Width+2 >= pBoxX &&
					S1_Landleft_Y-2 <= pBoxY2) ||
				//�E�̏�
				(S1_Landright_X-2 <= pBoxX2 && S1_Landright_Width+2 >= pBoxX &&
					S1_Landright_Y-2 <= pBoxY2) ||
				//�󒆂̏�
				(S1_Flooting_X-2 <= pBoxX2 && S1_Flooting_Width+2 >= pBoxX &&
					S1_Flooting_Y-2 <= pBoxY2 && S1_Flooting_height+2 >= pBoxY)
				)
			{

				if (playerX + 64 > 0)
				{
					//���ړ�
					if (InputX < -1)
					{

						if (Speed > -4.5)
						{
							Speed -= 0.05f;
							if (-1.0 > Speed)
							{
								Speed -= 0.3;
							}
						}
						//�A�j���[�V����
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

						if (Speed < 4.5)
						{
							Speed += 0.05f;
							if (1.0 < Speed)
							{
								Speed += 0.3;
							}
						}

						//�A�j���[�V����
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
					Speed *= 0.9f;


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
				PlayerFlg = 2;
				HitFlg = 0;
			}

			//�n�ʂɗ����Ă��Ȃ����
			else
			{
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

				if (playerX + 64 > 0)
				{
					//���ړ�
					if (InputX < -1)
					{
						if (UpFlg == 1 && Speed > -4.2)
						{
							Speed -= 1.1f;
							if (Speed > -4.2)Speed = -4.2;
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
						if (UpFlg == 1 && Speed < 4.2)
						{
							Speed += 1.1f;
							if (Speed > 4.2)Speed = 4.2;
						}


						playerLR = 2;
						/*playerY += 6;*/
					}
				}

				if (InputX == 0 || UpFlg == 0)
				{
					//�����̍쐬
					Speed *= 0.96f;
				}
				Gvy += 0.1f;
				PlayerFlg = 1;
				HitFlg = 0;
			}
			//���n�ʕ�
			if (S1_LEinSide_X <= pBoxX2 && S1_LEinSide_Width >= pBoxX &&
				S1_LEinSide_height >= bBoxY && S1_LEinSide_Y + 1 < pBoxY2) {
				HitFlg = 1;
			}
			// �E�n�ʕ�
			if (S1_LIinSide_X <= pBoxX2 && S1_LIinSide_Width >= pBoxX &&
				S1_LIinSide_height>= bBoxY && S1_LIinSide_Y + 1 < pBoxY2) {
				HitFlg = 2;
			}
			//�󒆏�����
			if (S1_FinSide_X <= pBoxX2 && S1_FinSide_W >= pBoxX &&
				S1_FinSide_Y + 1 < pBoxY2 && S1_FinSide_H - 1 >= bBoxY && Speed > 0.5) {
				HitFlg = 2;
			}
			// �󒆏��E��
			if (S1_FinSide_X <= pBoxX2 && S1_FinSide_W >= pBoxX &&
				S1_FinSide_Y + 1 < pBoxY2 && S1_FinSide_H - 1 >= bBoxY && Speed < -0.5) {
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
			backlash();
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
			if (bBoxY > 480) {
				PlayerFlg = 0;
			}
		}
	}
	else if (PlayerFlg == 0) {
		Time++;
		if (Time >= 60) {
			life();
		}
	}

	if (PlayerFlg == 4) {
		playerY += 3.0f;
	}

	
	return this;
}

void Player::Draw() const
{
#if _DEBUG
	DrawFormatString(0, 40, 0xffffff, "Speed:%5.2f", Speed, TRUE);
	DrawFormatString(0, 60, 0xffffff, "%f", a, TRUE);
	DrawFormatString(0, 80, 0xffffff, "�v���C���[���W X0:%d Y0:%d X1:%d Y1:%d",pBoxX,pBoxY,pBoxX2,pBoxY2, TRUE);

	DrawFormatString(0, 100, 0xffffff, "�v���C���[�̏�� %d�@0:�n�ʁ@1:��", PlayerFlg, TRUE);

	DrawFormatString(0, 160, 0xffffff, "%d", AnimCount, TRUE);

	DrawBox(pBoxX, pBoxY, pBoxX2, pBoxY2, 0xff2255, FALSE);//�v���C���[��box
	DrawBox(bBoxX, bBoxY, bBoxX2, bBoxY2, 0xff2255, FALSE);//���D��box

#endif _DEBUG
	
	//�����ŕ`��
	//������
	if (PlayerFlg != 0) {
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
}

void Player::pUP()
{
	UpNum = 4;
	UpFlg = 1;
}

void Player::backlash()
{
	// �����ɐG�ꂽ�Ƃ�
	if (HitFlg == 1 && Speed < -0.5) {
		Speed *= -0.8;
	}
	// �E���ɐG�ꂽ�Ƃ�
	if (HitFlg == 2 && Speed > 0.5) {
		Speed *= -0.8;
	}
}

void Player::life()
{
	if (PlayerFlg == 0 && Life == 2 || Life == 1)
	{
		PlayerFlg = 1;
		Life--;
		playerX = 100;
		playerY = 336;
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

		
		Time = 0;
	}
	else if(PlayerFlg == 0 && Life == 0)
	{
		
	}
}