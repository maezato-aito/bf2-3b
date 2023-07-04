#include "GameMain.h"
#include "DxLib.h"

GameMain::GameMain()
{
	stage = new Stage();
}

GameMain::~GameMain()
{
	delete stage;
}

AbstractScene* GameMain::Update()
{
	return this;
}

void GameMain::Draw() const
{
	stage->Stage1();
	DrawFormatString(640, 360, 0xffffff, "GameMain");
}

