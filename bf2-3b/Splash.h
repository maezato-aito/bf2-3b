#pragma once


class Splash
{
private:
    
    int SplashAnim;		//アニメーションの添字
    int Splashimg[4];
    int SESplash;
public:
    static int SplashAnimCount;		//水しぶきのアニメーションのカウント
    //コンストラクタ
    Splash();

    //デストラクタ
    ~Splash();

    //描画以外の処理
    void Update();

    //描画処理
    void Draw();
};