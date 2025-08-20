#pragma once
class Title:public IGameObject
{
public:
	Title();
	~Title();
	void Render(RenderContext& rc);
	void Update();
	SpriteRender spriteRender;
	SoundSource* titleBGM;
};

