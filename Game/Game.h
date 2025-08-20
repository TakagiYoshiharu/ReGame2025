#pragma once

#include "Level3DRender/LevelRender.h"
#include"sound/SoundSource.h"
class Player;
class Background;
class GameCamera;
class GameClaer;
class GameOver;
class Game : public IGameObject
{
public:
	Game() {};
	~Game();
	bool Start();
	void Update();
	void Render(RenderContext& rc);
private:
	ModelRender m_modelRender;
	Vector3 m_position;
	Background* background;
	GameCamera* gameCamera;
	Player* player;
	SkyCube* m_skyCube;
	SoundSource* gameBGM;
};

