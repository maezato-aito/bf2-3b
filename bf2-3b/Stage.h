#pragma once
class Stage
{
private:
    int FlootingImg[7];  // �󒆏��̉摜
    int LandImg[4];     // �n�ʂ̉摜
    int SeaImg;    // �C�̉摜
    
public:
    Stage();    //�R���X�g���N�^
    ~Stage();   //�f�X�g���N�^
   
    void Update();      //�`��ȊO�̏���
    void Draw()const;   //�`�揈��

    void Stage1();      // �X�e�[�W�P
};
