#pragma once

class Stage
{
private:
    int FlootingImg[7];  // �󒆏��̉摜
    int LandImg[4];     // �n�ʂ̉摜
    int SeaImg;    // �C�̉摜
    int CloudImg[3];     // �_�̉摜 
    
public:
    Stage();    //�R���X�g���N�^
    ~Stage();   //�f�X�g���N�^
   
    void Update();      //�`��ȊO�̏���
    void Draw()const;   //�`�揈��

    void Stage1();      // �X�e�[�W�P

    int S1_Flooting_X, S1_Flooting_Y;   // �X�e�[�W�P�E�Q�̋󒆏��̍��W
    int S1_Landright_X, S1_Landright_Y;     // �X�e�[�W�P�`�R�̒n�ʁi�E�j�̍��W
    int S1_Landleft_X, S1_Landleft_Y;     // �X�e�[�W�P�`�R�̒n�ʁi���j�̍��W
    int S1_Cloud_X, S1_Cloud_Y;     // �X�e�[�W�P�̉_�̍��W

    int Searight_X, Searight_Y;   // �C�i�E�j�̍��W
    int Sealeft_X, Sealeft_Y;   // �C�i���j�̍��W
};
