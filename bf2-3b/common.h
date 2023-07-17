#pragma once

// ステージ１・２の空中床座標
#define S1_Flooting_X (180)
#define S1_Flooting_Y (280)
// 空中床の左側面
#define S1_Flooting_LEFT (S1_Flooting_X,S1_Flooting_Y)

#define S1_Flooting_Width (S1_Flooting_X + 280)
#define S1_Flooting_height (S1_Flooting_Y + 20)

#define S1_Flooting_RIGHT (S1_Flooting_Width,S1_Flooting_height)
// ステージ１・２の地面座標
#define S1_Landright_X (480)
#define S1_Landright_Y (410)
#define S1_Landright_Width (S1_Landright_X + 160)
#define S1_Landright_height (S1_Landright_Y + 40)
#define S1_Landleft_X (0)
#define S1_Landleft_Y (410)
#define S1_Landleft_Width (S1_Landleft_X + 160)
#define S1_Landleft_height (S1_Landleft_Y + 40)

// ステージ１の雲座標
#define S1_Cloud_X (300)
#define S1_Cloud_Y (100)

// 海の座標
#define Searight_X (0)
#define Searight_Y (440)
#define Sealeft_X (320)
#define Sealeft_Y (440)