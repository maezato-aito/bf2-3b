#pragma once
class Fish

{
private:
    float fishX, fishY;
    int Fishimg[10];
public:
    //�R���X�g���N�^
    Fish();

    //�f�X�g���N�^
    ~Fish();

    //�`��ȊO�̏���
    void Update();

    //�`�揈��
    void Draw();
};

