#pragma once
#include "AbstractScene.h"
#include "Stage.h"

class GameMain :
    public AbstractScene
{
private:
    Stage* stage;
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


