#pragma once
#include "AbstractScene.h"
class GameMain :
    public AbstractScene
{
public:
    //�R���X�g���N�^
    GameMain();

    //�f�X�g���N�^
    ~GameMain();

    //�`��ȊO�̏���
    AbstractScene* Update()override;

    //�`�揈��
    void Draw()const override;
};


