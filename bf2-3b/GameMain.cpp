#include "GameMain.h"
#include "DxLib.h"
GameMain::GameMain()
{
	stage = new Stage();
	PlayChar = new Player();
}

GameMain::~GameMain()
{
	delete stage;
	delete PlayChar;
}

AbstractScene* GameMain::Update()
{
	PlayChar->Update();
	return this;
}

void GameMain::Draw() const
{
	
	stage->Stage1();
	PlayChar->Draw();
	DrawFormatString(640, 360, 0xffffff, "GameMain");
}

