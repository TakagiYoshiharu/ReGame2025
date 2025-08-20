#include "stdafx.h"
#include "Title.h"
#include"Game.h"

Title::Title() {
	spriteRender.Init("Assets/sprite/title.dds", 1920.0f, 1080.0f);

	g_soundEngine->ResistWaveFileBank(0,"Assets/sound/AS_1428728_�s�R�s�R���t�@�~�R����8bit�u�M�E�M��.wav");

	titleBGM = NewGO<SoundSource>(0);
	titleBGM->Init(0);
	titleBGM->Play(true);
}

Title::~Title() {
	DeleteGO(titleBGM);
}

void Title::Update() {
	if (g_pad[0]->IsTrigger(enButtonA)) {
		NewGO<Game>(0);
		DeleteGO(this);
	}
}

void Title::Render(RenderContext& rc) {
	spriteRender.Draw(rc);
}
