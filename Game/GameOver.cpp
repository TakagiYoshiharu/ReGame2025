#include "stdafx.h"
#include "GameOver.h"
#include"Game.h"
#include"Title.h"
#include"sound/SoundEngine.h"

GameOver::GameOver() {
	spriteRender.Init("Assets/sprite/GameOver.DDS", 1920.0f, 1080.0f);

	g_soundEngine->ResistWaveFileBank(0, "Assets/sound/AS_1593698_育成ゲーム・ワルツ・ペット・かわいい.wav");
	  
	gameOverBGM = NewGO<SoundSource>(0);
	gameOverBGM -> Init(0);
	gameOverBGM->Play(true);
}

GameOver::~GameOver() {
	DeleteGO(gameOverBGM);
}

void GameOver::Update() {
	if (g_pad[0]->IsTrigger(enButtonX)) {
		NewGO<Title>(0, "Title");
		DeleteGO(this);
	}

}

void GameOver::Render(RenderContext& rc) {
	spriteRender.Draw(rc);
}