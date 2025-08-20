#pragma once
class Background :public IGameObject {
public:
	Background();
	~Background();

	void Render(RenderContext& rc);

	ModelRender modelRender;
	PhysicsStaticObject physicsStaticObject;
};

