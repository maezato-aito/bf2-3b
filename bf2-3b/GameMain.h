#pragma once
#include "AbstractScene.h"
#include "Stage.h"
#include"Player.h"
#include "Enemy.h"
#include "thunder.h"
#include"bubble.h"
#include"fish.h"
#include "UI.h"
#include"GameOver.h"
#include"Splash.h"
class GameMain :
    public AbstractScene
{
private:
    Stage* stage;
    Player* PlayChar;
    Enemy* EnemyChar;
    thunder* Thunder;
    Bubble* bubble;
    Fish* fish;
    UI* ui;
    GameOver* gameover;
    Splash* splash;
public:
    //コンストラクタ
    GameMain();

    //デストラクタ
    ~GameMain();

    //描画以外の処理
    AbstractScene* Update()override;

    //描画処理
    void Draw()const override;
};


