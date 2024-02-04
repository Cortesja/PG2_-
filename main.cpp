#include <Novice.h>
#include "Object.h"

#include "Player.h"
#include "Enemy.h"
#include "EnemyA.h"
#include "EnemyB.h"
#include "Bullet.h"

const char kWindowTitle[] = "GC1C_07_コーテスジャレッドアレン";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	Player* player = new Player({ kWindowWidth / 2 ,600 }, { 25.0f,25.0f }, true);
	Enemy* enemy[2];

	enemy[0] = new EnemyA({ 100.0f,300.0f }, 4, {15.0f, 15.0f});
	enemy[1] = new EnemyB({ 150.0f, 500.0f }, 6, {30.0f, 30.0f});

	int scene = gameTitle;

	int gameTitleHandler = Novice::LoadTexture("./gameTitle.png");

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		switch (scene) {
		case gameTitle:
			Novice::DrawSprite(0, 0, gameTitleHandler, 1.0f, 1.0f, 0.0f, WHITE);

			player->isAlive_ = true;

			if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
				enemy[0]->SetPosition({ 100.0f,300.0f });
				enemy[1]->SetPosition({ 150.0f, 500.0f });
				player->SetPosition({ (float)kWindowWidth / 2, 600.0f });
				scene += 1;
			}

			break; //gameTitle
		case gameMain:
			player->Update(keys, preKeys);

			for (int i = 0; i < 2; i++) {

				if (enemy[i]->isAlive_) {
					bool chkCollision0, chkCollision1;
					chkCollision0 = chkObjHit(player->GetPosition(), player->GetSize(), enemy[i]->GetPosition(), enemy[i]->GetSize());
					chkCollision1 = chkObjHit(player->bullet->GetPosition(), player->bullet->GetSize(), enemy[i]->GetPosition(), enemy[i]->GetSize());

					if (chkCollision0) {
						player->isAlive_ = false;
						scene += 1;
					}
					if (chkCollision1) {
						enemy[i]->isAlive_ = false;
					}
				}

				enemy[i]->Update();
			}

			///
			/// ↓描画処理ここから
			///

			for (int i = 0; i < 2; i++) {
				enemy[i]->Draw();
			}

			player->Draw();

			///
			/// ↑描画処理ここまで
			///
			break; //gameMain
		case gameOver:
			int gameOverHandler = Novice::LoadTexture("./gameOver.png");

			Novice::DrawSprite(0, 0, gameOverHandler, 1.0f, 1.0f, 0.0f, WHITE);

			if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
				scene = gameTitle;
			}

			break; //gameOver
		}

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	player->~Player();
	for (int i = 0; i < 2; i++) {
		enemy[i]->~Enemy();
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
