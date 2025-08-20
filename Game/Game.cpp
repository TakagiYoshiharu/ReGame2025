#include "stdafx.h"
#include "Game.h"
#include"Player.h"
#include"Background.h"
#include"GameCamera.h"
#include"Item.h"
#include"GameOver.h"
#include"GameClear.h"
#include"Title.h"
#include"sound/SoundEngine.h"
bool Game::Start()
{
	player = NewGO<Player>(0, "BattleCharacter");
	m_skyCube = NewGO<SkyCube>(0, "skycube");

	player->ItemCount = 0;

	background = NewGO<Background>(0);
	gameCamera = NewGO<GameCamera>(0);

	Item* item1 = NewGO<Item>(0, "Item");
	item1->position = { 0.0f,25.0f,1200.0f };
	item1->firstPosition = item1->position;

	Item* item2 = NewGO<Item>(0, "Item");
	item2->position = { 0.0f,425.0f,2500.0f };
	item2->firstPosition = item2->position;

	Item* item3 = NewGO<Item>(0, "Item");
	item3->position = { 0.0f,600.0f,4000.0f };
	item3->firstPosition = item3->position;

	Item* item4 = NewGO<Item>(0, "Item");
	item4->position = { 0.0f,-850.0f,4100.0f };
	item4->firstPosition = item4->position;

	Item* item5 = NewGO<Item>(0, "Item");
	item5->position = { 0.0f,-240.0f,6475.0f };
	item5->firstPosition = item5->position;

	g_soundEngine->ResistWaveFileBank(0, "Assets/sound/AS_1211258_ファミコン風_アクションゲームのBGM.wav");
	gameBGM = NewGO<SoundSource>(0);
	gameBGM->Init(0);
	gameBGM->Play(true);

	return true;

}

void Game::Update()
{
	if (player->m_position.y < -1500.0f) {
		NewGO<GameOver>(0, "gameOver");
		DeleteGO(this);
	}
	if (player->ItemCount >= 5) {
		NewGO<GameClear>(0, "gameClear");
		DeleteGO(this);
	}
}

void Game::Render(RenderContext& rc)
{
}

Game::~Game() {
	DeleteGO(player);
	DeleteGO(gameCamera);
	DeleteGO(background);
	DeleteGO(m_skyCube);
	DeleteGO(gameBGM);
}

