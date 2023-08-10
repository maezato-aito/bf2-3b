#pragma once

class Stage
{
private:
    int FlootingImg[7];  // 空中床の画像
    int LandImg[4];     // 地面の画像
    int SeaImg;    // 海の画像
    int CloudImg[3];     // 雲の画像 

    int Stage2Sample;
    int Stage3Sample;
    int Stage4Sample;
    int Stage5Sample;
    
public:
    Stage();    //コンストラクタ
    ~Stage();   //デストラクタ
   
    void Update();      //描画以外の処理
    void Draw()const;   //描画処理

    static float fishBox;
    void Stage1();      // ステージ１
    void Stage2();      // ステージ１
    void Stage3();      // ステージ１
    void Stage4();      // ステージ１
    void Stage5();      // ステージ１

};
