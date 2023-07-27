#include"bubble.h"
#include"DxLib.h"

Bubble::Bubble()
{
	//–A‚ÌˆÊ’u
	 bubbleX=250;
	 bubbleY=480;

	 //–A‚Ìã¸—Ê
	 bubbleUp = 0.75;

	 //–A‚Ì‰¡‚ÌˆÚ“®—Ê
	 bubbleSide = 0.1;

	//–A‚Ì‰Eã
	 bX0=bubbleX-25;
	 bY0=bubbleY-25;

	//–A‚Ì¶‰º
	 bX1=bubbleX+25;
	 bY1=bubbleY+25;

	//‰æ‘œ‚Ì“Ç‚İ‚İ
	LoadDivGraph("images/Stage/Stage_BubbleAnimation.png", 4, 4, 1, 64, 64, bubbleImg);
}
Bubble::~Bubble()
{

}
void Bubble::Update()
{
	//–A‚ÌˆÊ’u
	bubbleY-=bubbleUp;
	bubbleX += bubbleSide;
	//–A‚Ì‰Eã
	bX0 = bubbleX - 25;
	bY0 = bubbleY - 25;

	//–A‚Ì¶‰º
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
	DrawFormatString(350, 0, 0xffffff, "–A‚ÌÀ•W X:%3.2f Y:%3.2f",bubbleX,bubbleY,  TRUE);
}
