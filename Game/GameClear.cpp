#include "stdafx.h"
#include "GameClear.h"
#include"Game.h"
#include"Title.h"
GameClear::GameClear() {
	spriteRender.Init("Assets/sprite/gameclear.dds", 1920.0f, 1080.0f);

	g_soundEngine->ResistWaveFileBank(0, "Assets/sound/AS_124466_マリオ風ファミコン曲_ステージクリア.wav");

	gameClearBGM = NewGO<SoundSource>(0);
	gameClearBGM->Init(0);
	gameClearBGM->Play(true);
}

GameClear::~GameClear() {
	DeleteGO(gameClearBGM);
}

void GameClear::Update() {
	if (g_pad[0]->IsTrigger(enButtonX)) {
		NewGO<Title>(0, "Title");
		DeleteGO(this);
	}
}

void GameClear::Render(RenderContext& rc) {
	spriteRender.Draw(rc);
}