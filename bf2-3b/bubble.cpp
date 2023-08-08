#include"bubble.h"
#include"DxLib.h"
#include"Player.h"

Bubble::Bubble()
{
	//�A�̈ʒu
	 bubbleX=250;
	 bubbleY=480;

	 //�A�̏㏸��
	 bubbleUp = 0.75;

	 //�A�̉��̈ړ���
	 bubbleSide = 0.5f;

	//�A�̉E��
	 bX0=bubbleX-25;
	 bY0=bubbleY-25;

	//�A�̍���
	 bX1=bubbleX+25;
	 bY1=bubbleY+25;

	 //�A�j���[�V�����p�J�E���^
	 bubbleC = 0;
	 bubbleAC = 0;

	 bAv = 0;
	 b=0;
	//�摜�̓ǂݍ���
	LoadDivGraph("images/Stage/Stage_BubbleAnimation.png", 4, 4, 1, 64, 64, bubbleImg);
}
Bubble::~Bubble()
{

}
void Bubble::Update()
{
	//�A�̈ʒu
	bubbleY-=bubbleUp;
	bubbleX += bubbleSide;
	//�A�̉E��
	bX0 = bubbleX - 30;
	bY0 = bubbleY - 30;

	//�A�̍���
	bX1 = bubbleX + 30;
	bY1 = bubbleY + 30;

	if (bubbleX<215 || 285< bubbleX ) 
	{
		bubbleSide *= -1;
	}

	if (bubbleY <= -25)
	{
		bubbleUp=0;
		bubbleSide = 0;
	}
	//�A�j���[�V����
	if (bubbleY >= 0)
	{
		bubbleC = GetNowCount();
		b = bubbleC % 1000;

		if (b < 10)
		{
			bAv++;
			
		}

		if (bAv < 1)
		{
			bubbleAC = 0;
		}
		else if (1 < bAv < 2)
		{
			bubbleAC = 1;
		}
		else if (2 < bAv < 3)
		{
			bubbleAC = 0;
		}
		else if (3 < bAv < 4)
		{
			bubbleAC = 2;
		}
	}
	//�Ԃ�������
	/*if (
		(bX0 <= pBoxX2 && bX1 >= pBoxX &&
			bY0 <= pBoxY2 && bY1 >= pBoxY))
	{
		bubbleAC == 3;
	}*/
}
void Bubble::Draw()
{
	DrawExtendGraph(bX0, bY0,bX1,bY1 ,bubbleImg[bubbleAC], TRUE);
#if _DEBUG
	DrawFormatString(350, 0, 0xffffff, "�A�̍��W X:%3.2f Y:%3.2f",bubbleX,bubbleY,  TRUE);
	DrawFormatString(350, 20, 0xffffff, "�A�̎��:%d",bubbleAC,  TRUE);
	DrawFormatString(350, 40, 0xffffff,		"����: % d",bAv,  TRUE);
#endif _DEBUG
}
