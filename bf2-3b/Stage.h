#pragma once

class Stage
{
private:
    int FlootingImg[7];  // 空中床の画像
    int LandImg[4];     // 地面の画像
    int SeaImg;    // 海の画像
    int CloudImg[3];     // 雲の画像 
    
public:
    Stage();    //コンストラクタ
    ~Stage();   //デストラクタ
   
    void Update();      //描画以外の処理
    void Draw()const;   //描画処理

    void Stage1();      // ステージ１

    int S1_Flooting_X, S1_Flooting_Y;   // ステージ１・２の空中床の座標
    int S1_Landright_X, S1_Landright_Y;     // ステージ１～３の地面（右）の座標
    int S1_Landleft_X, S1_Landleft_Y;     // ステージ１～３の地面（左）の座標
    int S1_Cloud_X, S1_Cloud_Y;     // ステージ１の雲の座標

    int Searight_X, Searight_Y;   // 海（右）の座標
    int Sealeft_X, Sealeft_Y;   // 海（左）の座標
};
