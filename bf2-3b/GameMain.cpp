#include "GameMain.h"
#include "DxLib.h"

GameMain::GameMain()
{
}

GameMain::~GameMain()
{
}

AbstractScene* GameMain::Update()
{
	return this;
}

void GameMain::Draw() const
{
	DrawFormatString(640, 360, 0xffffff, "GameMain");
}

