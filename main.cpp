#include <Novice.h>
#include "Player.h"
#include "Enemy.h"
#define _USE_MATH_DEFINES
#include <math.h>

const char kWindowTitle[] = "GC1C_01_アダチ_カズマ_タイトル";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	//画像
	int graphHandle0 = 0;
	graphHandle0 = Novice::LoadTexture("./DDD.png");
	int graphHandle1 = 0;
	graphHandle1 = Novice::LoadTexture("./tot.png");
	int graphHandle2 = 0;
	graphHandle2 = Novice::LoadTexture("./bullet11.png");
	int graphHandle3 = 0;
	graphHandle3 = Novice::LoadTexture("./inseki.png");
	int graphHandle4 = 0;
	graphHandle4 = Novice::LoadTexture("./taitoru.png");
	int graphHandle5 = 0;
	graphHandle5 = Novice::LoadTexture("./gamenn.png");
	int graphHandle6 = 0;
	graphHandle6 = Novice::LoadTexture("./kuria.png");
	int graphHandle7 = 0;
	graphHandle7 = Novice::LoadTexture("./maketa.png");
	int scene = 0;

	//自機
	Player* player = new Player(245, 500, 5, 25, 3, 1);



	//敵機
	Enemy* enemy = new Enemy(0, 0, 0, 0, 30, 0, 3, 1, 25, 32);


	//弾
	int Bposx = 0;
	int Bposy = 0;
	int BsizeX = 8;
	int BsizeY = 8;
	int Bspeed = 10;
	int IsBshot = false;

	//攻撃
	int Aposx = 0;
	int Aposy = 0;
	int Asizex = 1;
	int Asizey = 1;
	int Aspeed = 0;
	int IsAshot = 0;
	
	int enemyradius = 1;
	int isimoshot = false;
	int enemyimospeed = 5;

	//シーン
	int PosX = 0;
	int PosY = 0;
	int posY1 = -600;
	int radiusX = 50;
	int radiusY = 50;

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		if (scene == 0)
		{
			player->SetPosX(245);
			player->SetPosY(500);
			player->SetMHp(3);
			player->SetIsAlive(1);

			enemy->SetHp(25);
			enemy->SetIsAlive(1);
			enemy->SetRespornCount(3);

			if (keys[DIK_H] && preKeys[DIK_H] == 0)
			{
				scene = 1;

			}
		}


		if (scene == 1)
		{
			//シーン
			player->Update(keys, preKeys);
			enemy->Update();

			//背景
			PosY = PosY + 5;
			posY1 = posY1 + 5;
			if (posY1 == 600)
			{
				posY1 = -600;

			}
			if (PosY == 600)
			{
				PosY = -600;
			}

			//弾
			if (IsBshot == false)
			{
				if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0)
				{
					IsBshot = true;
					Bposx = player->GetPosX() + 9;
					Bposy = player->GetPosY() - 11;
				}
			}


			//敵弾

			//芋けんぴ判定
			/*if (enemy->GetIsAlive() == true)*/

			if (enemy->GetIsAlive() == true)
			{
				if (isimoshot == false)
				{
					isimoshot = true;
					Aposx = enemy->GetPosx() + enemy->GetRadius();
					Aposy = enemy->GetPosy() + enemy->GetRadius();
					/*break;*/
				}
			}


			if (isimoshot == true)
			{
				Aposy = Aposy + enemyimospeed;

				int d = (player->GetPosX() - Aposx) * (player->GetPosX() - Aposx) + (player->GetPosY() - Aposy) * (player->GetPosY() - Aposy);

				int r = (player->GetRadius() + Asizey) * (player->GetRadius() + Asizex);

				if (r == d || r > d)
				{
					isimoshot = false;
					player->SetMHp(player->GetMHp() - 1);
				}
			}


			if (Aposy >= 550)
			{
				isimoshot = false;
			}

			//当たり判定
			if (IsBshot == true)
			{
				Bposy = Bposy - Bspeed;

				if (enemy->GetIsAlive() == true)
				{
					float a = enemy->GetPosx() - Bposx;
					float b = enemy->GetPosy() - Bposy;
					float d = sqrtf(a * a + b * b);

					if (d <= enemy->GetRadius() + BsizeX)
					{
						IsBshot = false;
						enemy->SetHp(enemy->GetHp() - 1);
					}
				}
			}

			if (Bposy <= 0)
			{
				IsBshot = false;
			}

			//当たり判定
			if (enemy->GetIsAlive() == true && player->GetIsAlive() == true)
			{
				float a = enemy->GetPosx() - player->GetPosX();
				float b = enemy->GetPosy() - player->GetPosY();
				float d = sqrtf(a * a + b * b);

				if (d <= player->GetRadius() + enemy->GetRadius())
				{
					player->SetMHp(player->GetMHp() - 1);
				}
			}


			if (player->GetMHp() == 0)
			{
				scene = 3;
			}


			if (enemy->GetHp() == 0)
			{
				enemy->SetIsAlive(0);
				enemy->SetHp(25);
				enemy->SetRespornCount(enemy->GetRespornCount() - 1);
				/*scene = 3;*/
			}

			if (enemy->GetRespornCount() == 0)
			{
				scene = 2;
			}

		}


		if (scene == 3)
		{
			if (keys[DIK_Z] && preKeys[DIK_Z] == 0)
			{
				scene = 0;

			}
		}


		if (scene == 2)
		{
			if (keys[DIK_Z] && preKeys[DIK_Z] == 0)
			{
				scene = 0;

			}
		}

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		//タイトル
		if (scene == 0)
		{
			Novice::DrawSprite(0, 0, graphHandle4, 1, 1, 0.0f, WHITE);
		}
		//ゲーム画面
		if (scene == 1)
		{
			Novice::DrawSprite(PosX, PosY, graphHandle5, 1, 1, 0.0f, WHITE);
			Novice::DrawSprite(PosX, posY1, graphHandle5, 1, 1, 0.0f, WHITE);

			//攻撃
			if (isimoshot == true)
			{
				Novice::DrawSprite(Aposx, Aposy, graphHandle3, enemyradius, enemyradius, 0.0f, WHITE);
			}

			/*if (scene == 1)
			{

			}*/
			player->Draw();
			enemy->Draw();

			//弾
			if (scene == 1)
			{
				if (IsBshot == true)
				{
					Novice::DrawSprite(Bposx, Bposy, graphHandle2, 1, 1, 0.0f, WHITE);

				}

			}

			Novice::ScreenPrintf(0, 0, "%d", enemy->GetHp());
			Novice::ScreenPrintf(0, 15, "%d MyHp", player->GetMHp());
			Novice::ScreenPrintf(0, 30, "%d", isimoshot);
		}


		//クリア
		if (scene == 2)
		{
			Novice::DrawSprite(0, 0, graphHandle6, 1, 1, 0.0f, WHITE);
		}
		//ゲームオーバー
		if (scene == 3)
		{
			Novice::DrawSprite(0, 0, graphHandle7, 1, 1, 0.0f, WHITE);
		}

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
