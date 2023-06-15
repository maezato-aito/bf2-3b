/********************************************************************
** 第3章 ゲームプログラミングの基本
** (1) ゲームループの基本形
********************************************************************/
#include "DxLib.h"
/***********************************************
* 変数の宣言
***********************************************/
int g_LoopCount = 0;
/***********************************************
* プログラムの開始
***********************************************/
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,

	LPSTR lpCmdLine, int nCmdShow)

{
	// ウィンドウモードで起動する
	ChangeWindowMode(TRUE);
	// DX ライブラリの初期化処理:エラーが起きたら直ちに終了
	if (DxLib_Init() == -1) return -1;
	// 描画先画面を裏にする
	SetDrawScreen(DX_SCREEN_BACK);
	// ゲームループ
	while (ProcessMessage() == 0) {
		// 画面の初期化
		ClearDrawScreen();
		// ループカウンタの表示
		DrawFormatString(0, 0, GetColor(255, 255, 255),

			"LoopCount = %d ", g_LoopCount++);

		// 裏画面の内容を表画面に反映
		ScreenFlip();
	}
	// DX ライブラリ使用の終了処理
	DxLib_End();
	// ソフトの終了
	return 0;
}