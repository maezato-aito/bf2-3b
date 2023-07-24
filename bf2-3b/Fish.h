#pragma once
class Fish

{
private:
    float fishX, fishY;
    int Fishimg[10];
public:
    //コンストラクタ
    Fish();

    //デストラクタ
    ~Fish();

    //描画以外の処理
    void Update();

    //描画処理
    void Draw();
};

