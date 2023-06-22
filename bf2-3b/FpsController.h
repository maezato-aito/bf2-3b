#pragma once

class FpsController
{
private:

    int frame_time; //1�t���[���̎���(�~���b)
    int wait_time; //�҂�����
    int last_time, now_time; //�Ō�Ɏ擾�������ԂƁC���̎���
    float count; //�t���[���̃J�E���g
    float fps; //�\�����邵��FPS�l
    int update_time; //�\���l���X�V���鎞��
    int last_update; //�Ō�ɕ\���l���X�V��������
private:

    //������
    void Init(float RefreshRate, int UpdateTime);
public:

    //�R���X�g���N�^
    FpsController(float RefreshRate, int UpdateTime)
    {
        Init(RefreshRate, UpdateTime);
    }

    FpsController()
    {
        Init(60.0f, 800);
    }

    //�҂����Ԃ̌v�Z
    void Wait();

    //FPS�l�̌v�Z
    float Get();

    //�������܂Ƃ߂�����
    float All()
    {
        Get();
        Wait();
        return (fps);
    }
};

