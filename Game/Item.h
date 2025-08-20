#pragma once
class Player;
class Item:public IGameObject
{
public:
	Item();
	~Item();
	void Update();
	void Render(RenderContext& rc);
	void Move();
	void Rotation();
	ModelRender modelRender;
	Vector3 position;
	int moveState = 0;
	Vector3 firstPosition;
	Quaternion rotation;
	Player* player;
};

