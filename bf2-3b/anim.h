#pragma once

#pragma once
#include "AbstractScene.h"
class Anim :
    public AbstractScene
{
private:
    int AnimWork;
    int AnimFlg =0b0000;
    int UpdateTime;
    int balloon;
    int PlayerImage[32];
public:
    
    //コンストラクタ
    Anim();

    //デストラクタ
    ~Anim();

    void PlayerInit();

    void LoadImages();

    //描画以外の処理
    AbstractScene* Update()override;

    //描画処理
    void Draw()const override;

};
