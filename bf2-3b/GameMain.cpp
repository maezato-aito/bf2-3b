#include "GameMain.h"
#include "DxLib.h"
GameMain::GameMain()
{
	stage = new Stage();
	PlayChar = new Player();
	Thunder = new thunder();
}

GameMain::~GameMain()
{
	delete stage;
	delete PlayChar;
	delete Thunder;
}

AbstractScene* GameMain::Update()
{
	Thunder->Update();
	PlayChar->Update();
	return this;
}

void GameMain::Draw() const
{
	Thunder->D_thunder();
	stage->Stage1();
	PlayChar->Draw();
	DrawFormatString(640, 360, 0xffffff, "GameMain");
}

