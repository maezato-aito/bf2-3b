#pragma once
#include "AbstractScene.h"
#include "Stage.h"
#include"Player.h"
#include"thunder.h"

class GameMain :
    public AbstractScene
{
private:
    Stage* stage;
    Player* PlayChar;
    thunder* Thunder;
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


