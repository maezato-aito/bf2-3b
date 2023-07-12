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
    
    //�R���X�g���N�^
    Anim();

    //�f�X�g���N�^
    ~Anim();

    void PlayerInit();

    void LoadImages();

    //�`��ȊO�̏���
    AbstractScene* Update()override;

    //�`�揈��
    void Draw()const override;

};
