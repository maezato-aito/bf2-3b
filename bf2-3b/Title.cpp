#include "Title.h"
#include "DxLib.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include "PadInput.h"
#include "GameMain.h"
#include "FpsController.h"

Title::Title()
{
	TitleLogoimage = LoadGraph("images/Title/Title_Logo.png");

	TitleOimage	= LoadGraph("images/Title/Title_ModeSelect.png");
	TitleNOCimage = LoadGraph("images/Title/Title_Credit.png");
	LoadDivGraph("images/Title/Title_CursorAnimation.png", 4, 4,1, 32, 64,TitleBimage);

	bCount = 0;
	animImage = 0;
}

Title::~Title()
{
	DeleteGraph(TitleLogoimage);
}

AbstractScene* Title::Update()
{
	//アニメーション
	bCount++;
	if (0 <= bCount)
	{
		animImage = 0;
	}
	if (15<=bCount)
	{
		animImage = 1;
	}
	if (30 <= bCount)
	{
		animImage = 2;
	}
	if (45 <= bCount)
	{
		animImage = 3;
	}
	if (60 <= bCount)
	{
		animImage = 2;
	}
	if (75 <= bCount)
	{
		animImage = 1;
	}
	if (90 <= bCount)
	{
		bCount=0;
	}
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_B)) {
		return new GameMain();
	}

	return this;
}

void Title::Draw() const
{
	DrawFormatString(640, 360, 0xffffff, "TiTle");
	DrawFormatString(630, 600, 0xffffff, "BでGameMain");

	DrawRotaGraph(320, 125, 0.8f, 0,TitleLogoimage, TRUE);// タイトルロゴ表示
	DrawRotaGraph(320, 310, 0.8f, 0, TitleOimage, TRUE);//	選択肢表示
	DrawRotaGraph(320, 440, 0.8f, 0, TitleNOCimage, TRUE);// 社名表示

	DrawRotaGraph(170, 285, 0.8f, 0, TitleBimage[animImage], TRUE);// 社名表示, TRUE);// 風船表示
}