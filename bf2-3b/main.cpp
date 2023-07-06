/********************************************************************
** 第3章 ゲームプログラミングの基本
** (1) ゲームループの基本形
********************************************************************/
#include "DxLib.h"
#include "SceneManager.h"
#include "PadInput.h"
#include "Title.h"
#include "GameMain.h"
#include "FpsController.h"
#define FRAMRATE 60.0	// フレームレート

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
	double dNextTime = GetNowCount();

	SetMainWindowText("Balloon Fight");

	ChangeWindowMode(TRUE);	// ウィンドウモードで起動する

	SetAlwaysRunFlag(true);	// 常にアクティブ

	SetGraphMode(640, 480, 32);	// 画面サイズ

	
	if (DxLib_Init() == -1) return -1;	// DX ライブラリの初期化処理:エラーが起きたら直ちに終了

	SetDrawScreen(DX_SCREEN_BACK);	// 描画先画面を裏にする

	SceneManager* sceneMng;

	try 
	{
		sceneMng = new SceneManager((AbstractScene*)new GameMain());
	}
	catch (const char* err)
	{
		FILE* fp = NULL;

		DATEDATA data;

		GetDateTime(&data);

		// ファイルオープン
		fopen_s(&fp, "EffLog.txt", "a");

		// エラーデータの書き込み
		fprintf_s(fp, "%02d年 %02月 %02日 %02d時 %02d分 %02d秒 : % sがありません。\n", data.Year, data.Mon, data.Day, data.Hour, data.Min, data.Sec, err);

		return 0;
	}

	// ゲームループ
	while ((ProcessMessage() == 0) && (sceneMng->Update() != nullptr)) 
	{
		ClearDrawScreen();	// 画面の初期化
		PAD_INPUT::UpdateKey();
		sceneMng->Draw();
		
		ScreenFlip();	// 裏画面の内容を表画面に反映

		dNextTime += 1.0 / 60.0 * 1000.0;	// フレームレートの設定

		if (dNextTime > GetNowCount())
		{
			WaitTimer(static_cast<int>(dNextTime) - GetNowCount());
		}
		else { dNextTime = GetNowCount(); }		//補正
	}
	
	return 0;
}