#include"bubble.h"
#include"DxLib.h"

Bubble::Bubble()
{
	//�A�̈ʒu
	 bubbleX=250;
	 bubbleY=480;

	 //�A�̏㏸��
	 bubbleUp = 0.75;

	 //�A�̉��̈ړ���
	 bubbleSide = 0.1;

	//�A�̉E��
	 bX0=bubbleX-25;
	 bY0=bubbleY-25;

	//�A�̍���
	 bX1=bubbleX+25;
	 bY1=bubbleY+25;

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
	bX0 = bubbleX - 25;
	bY0 = bubbleY - 25;

	//�A�̍���
	bX1 = bubbleX + 25;
	bY1 = bubbleY + 25;

	if (bubbleX<245 || 255< bubbleX ) 
	{
		bubbleSide *= -1;
	}
	
	

	if (bubbleY <= -25)
	{
		bubbleUp=0;
		bubbleSide = 0;
	}
}
void Bubble::Draw()
{
	DrawExtendGraph(bX0, bY0,bX1,bY1 ,bubbleImg[0], TRUE);
	DrawFormatString(350, 0, 0xffffff, "�A�̍��W X:%3.2f Y:%3.2f",bubbleX,bubbleY,  TRUE);
}
