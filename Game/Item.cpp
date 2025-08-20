#include "stdafx.h"
#include "Item.h"
#include"Player.h"
#include"sound/SoundEngine.h"
#include"sound/soundSource.h"
Item::Item() {
	modelRender.Init("Assets/modelData/Item.tkm");

	player = FindGO<Player>("BattleCharacter");

	g_soundEngine->ResistWaveFileBank(2, "Assets/sound/AS_152054_GB＿シューティング01-07（アイテム.wav");
}

Item::~Item() {

}

void Item::Update()
{
	 
	Move();

	Rotation();

	modelRender.Update();

	Vector3 diff = player->m_position - position;
	if (diff.Length() <= 70.0f)
	{
		SoundSource* se = NewGO<SoundSource>(0);
		se->Init(2);
		se->Play(false);
		se->SetVolume(3.5f);
		player->ItemCount ++;
		DeleteGO(this);
	}
	if (player->m_position.y < -1500.0f) {
	
		DeleteGO(this);
	}
}

void Item::Move() {

	modelRender.SetPosition(position);
}

void Item::Rotation() {
	rotation.AddRotationDegY(2.0f);

	modelRender.SetRotation(rotation);
}

void  Item::Render(RenderContext& rc) {
	modelRender.Draw(rc);
}