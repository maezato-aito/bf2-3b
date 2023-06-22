#pragma once
#include "AbstractScene.h"
class Pause :
    public AbstractScene
{
public:
    //コンストラクタ
    Pause();

    //デストラクタ
    ~Pause();

    //描画以外の処理
    AbstractScene* Update()override;

    //描画処理
    void Draw()const override;
};

