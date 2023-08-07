#pragma once
#include "AbstractScene.h"
#include "Stage.h"
#include"Player.h"
#include "Enemy.h"
#include "thunder.h"
#include"bubble.h"
#include"fish.h"
#include "GameOver.h"
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
    GameOver* gameover;
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


