#include "GameMain.h"
#include "DxLib.h"
GameMain::GameMain()
{
	stage = new Stage();
	PlayChar = new Player();
	EnemyChar = new Enemy();
	Thunder = new thunder();
	fish = new Fish();
}


GameMain::~GameMain()
{
	delete stage;
	delete PlayChar;
	delete EnemyChar;
	delete Thunder;
}

AbstractScene* GameMain::Update()
{
	Thunder->Update();
	PlayChar->Update();
	EnemyChar->Update();
	return this;
}

void GameMain::Draw() const
{
	Thunder->D_thunder();
	stage->Stage1();
	PlayChar->Draw();
	EnemyChar->Draw();
	fish->Draw();
	DrawFormatString(640, 360, 0xffffff, "GameMain");
}

