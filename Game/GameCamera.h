#pragma once
class Player;
class GameCamera :public IGameObject
{
public:
	GameCamera();
	void Update();
	Player* player;
};

