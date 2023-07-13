#include "Title.h"
#include "DxLib.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include "PadInput.h"
#include "GameMain.h"
#include "FpsController.h"
Title::Title()
{
	/*Titleimage = LoadGraph("");*/
}

Title::~Title()
{
	/*DeleteGraph(Titleimage);*/
}

AbstractScene* Title::Update()
{
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_B)) {
		return new GameMain();
	}

	return this;
}

void Title::Draw() const
{
	DrawFormatString(640, 360, 0xffffff, "TiTle");
	DrawFormatString(630, 600, 0xffffff, "BでGameMain");
	/*DrawGraph();*/	// タイトル画像表示
}