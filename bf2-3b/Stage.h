#pragma once

class Stage
{
private:
    int FlootingImg[7];  // �󒆏��̉摜
    int LandImg[4];     // �n�ʂ̉摜
    int SeaImg;    // �C�̉摜
    int CloudImg[3];     // �_�̉摜 

    int Stage2Sample;
    int Stage3Sample;
    int Stage4Sample;
    int Stage5Sample;
    
public:
    Stage();    //�R���X�g���N�^
    ~Stage();   //�f�X�g���N�^
   
    void Update();      //�`��ȊO�̏���
    void Draw()const;   //�`�揈��

    static float fishBox;
    void Stage1();      // �X�e�[�W�P
    void Stage2();      // �X�e�[�W�P
    void Stage3();      // �X�e�[�W�P
    void Stage4();      // �X�e�[�W�P
    void Stage5();      // �X�e�[�W�P

};
