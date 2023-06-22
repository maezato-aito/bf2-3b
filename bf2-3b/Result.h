#pragma once
#include "AbstractScene.h"
class Result :
    public AbstractScene
{
public:
    //コンストラクタ
    Result();

    //デストラクタ
    ~Result();

    //描画以外の処理
    AbstractScene* Update()override;

    //描画処理
    void Draw()const override;
};


