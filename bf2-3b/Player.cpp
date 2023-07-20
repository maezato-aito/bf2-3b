#include"DxLib.h"
#include"Player.h"
#include"PadInput.h"
#include"common.h"

int Gvy = 0;

Player::Player()
{
	playerX = 100;
	playerY = 
	vx = 0.5;
	vy = 0.5;
	e = 0.8;
	LoadDivGraph("images/Player/Player_Animation.png",32,8,4,64,64,Playerimg);

}
Player::~Player()
{

}
AbstractScene* Player::Update()
{
	if ((PAD_INPUT::OnPressed(XINPUT_BUTTON_B)))
	{
		if (boxY > 4) 
		{
			Gvy = 3;
			// ������Ă���
			boxY -= Gvy;
			boxY2 -= Gvy;
		}
	}
	else if ((PAD_INPUT::OnButton(XINPUT_BUTTON_A)))
	{
		if (boxY > 4)
		{
			Gvy = 20;
			// ������Ă���
			boxY -= Gvy;
			boxY2 -= Gvy;
		}
	}

	
	//�n�ʂɗ����Ă��Ȃ��Ƃ�
	//�E�n��
	if ((S1_Landright_X <= boxX2 || S1_Landleft_Width >= boxX)&& S1_Landright_Y == boxY2) {
		Gvy = 0;
	}
	// �E�n�ʍ�����
	else if (S1_Landright_X <= boxX2 && S1_Landright_Y < boxY2) {
		/*vx -= vx*e;*/
		Gvy = 1;
		boxX -= vx;
		boxX2 -= vx;
		boxY += Gvy;
		boxY2 += Gvy;
	}
	//���n��
	else if (S1_Landleft_X <= boxX2 && S1_Landleft_Width >= boxX && S1_Landleft_Y == boxY2) {
		Gvy = 0;
	}
	// ���n�ʉE����
	else if (S1_Landleft_Width >= boxX && S1_Landleft_Y < boxY2) {
		Gvy = 1;
		boxX = 160;
		boxX2 = 210;
		boxY += Gvy;
		boxY2 += Gvy;
		
	}
	//�󒆏�
	else if (S1_Flooting_X <= boxX2 && S1_Flooting_Width >= boxX && S1_Flooting_Y == boxY2) {
		Gvy = 0;
	}
	else
	{
		// �W�����v��������Ă��Ȃ�
		Gvy = 1;
		boxY += Gvy;
		boxY2 += Gvy;
	}


	GetJoypadAnalogInput(&InputX, &InputY, DX_INPUT_PAD1);
	if (boxX > 0) {
		if (InputX < -1)
		{
			boxX -= 6;
			boxX2 -= 6;
		}
	}
	if (boxX2 < 640) {
		if (InputX > 1)
		{
			boxX += 6;
			boxX2 += 6;
		}
	}
	return this;
}

void Player::Draw() const
{
	DrawFormatString(0, 0, 0xffffff,"%d",InputX, TRUE);
	
	/*DrawBox(boxX, boxY,boxX2, boxY2+5, 0xffffff, TRUE);*/
	DrawBox(boxX, boxY, boxX2, boxY2 , 0xff2255, FALSE);
	DrawGraph(boxX-5, boxY -10, Playerimg[0], TRUE);
}
