#pragma once
class Player :public IGameObject
{
public:
	Player();
	~Player();
	void Update();
	void Render(RenderContext& renderContext);
	void Move();
	void ManageState();
	void PlayAnimation();
	void Rotation();
	enum EnAnimationClip {
		enAnimationClip_Idle,
		enAnimationClip_Walk,
		enAnimationClip_Jump,
		enAnimationClip_Run,
		enAnimationClip_Num,
	};
	//ここからメンバー変数。
	ModelRender modelRender;
	Vector3 m_position;
	CharacterController characterController;
	Vector3 moveSpeed;
	int jumpCount = 0;
	const int maxJumpCount=2 ;
	bool isGrounded = false;
	Quaternion rotation;
	AnimationClip animationClips[enAnimationClip_Num];
	int playerState = 0;
	int ItemCount = 0;
	bool isDashing = false;        // ダッシュ中かどうか
	const float walkSpeed = 120.0f;
	const float dashSpeed = 300.0f;  // ダッシュ時の速度

};

