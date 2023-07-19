#include "DxLib.h"
#include "thunder.h"

thunder::thunder()
{
	LoadDivGraph("x64/Release/images/stage/Stage_CloudAnimation.png", 3, 3, 1, 128, 64, ThunderImg);
	T_AnimImg = 1;
}

thunder::~thunder()
{
	/*DeleteGraph(Titleimage);*/
	DeleteGraph(ThunderImg[0]);
}
enum class STATE {
	white,
	green,
	yellow,
};
STATE state;

void thunder::Update()
{
	switch (state) {
	case STATE::white:

	}
}

void thunder::D_thunder()
{
	//DrawRotaGraph(boxX, boxY, 4.0f, 0, ThunderImg[T_AnimImg], TRUE, FALSE);
	DrawGraph(S1_Thunder_X, S1_Thunder_Y, ThunderImg[0], TRUE);
}