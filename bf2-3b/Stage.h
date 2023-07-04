#pragma once
class Stage
{
private:
    int FlootingImg[7];  // 空中床の画像
    int LandImg[4];     // 地面の画像
    int SeaImg;    // 海の画像
    
public:
    Stage();    //コンストラクタ
    ~Stage();   //デストラクタ
   
    void Update();      //描画以外の処理
    void Draw()const;   //描画処理

    void Stage1();      // ステージ１
};
