#pragma once


class Splash
{
private:
    
    int SplashAnim;		//�A�j���[�V�����̓Y��
    int Splashimg[4];
    int SESplash;
public:
    static int SplashAnimCount;		//�����Ԃ��̃A�j���[�V�����̃J�E���g
    //�R���X�g���N�^
    Splash();

    //�f�X�g���N�^
    ~Splash();

    //�`��ȊO�̏���
    void Update();

    //�`�揈��
    void Draw();
};