#include "stdafx.h"
#include "Player.h"

Player::Player() {
	animationClips[enAnimationClip_Idle].Load("Assets/animData/idle.tka");
	animationClips[enAnimationClip_Idle].SetLoopFlag(true);
	animationClips[enAnimationClip_Walk].Load("Assets/animData/walk.tka");
	animationClips[enAnimationClip_Walk].SetLoopFlag(true);
	animationClips[enAnimationClip_Jump].Load("Assets/animData/jump.tka");
	animationClips[enAnimationClip_Jump].SetLoopFlag(false);
	animationClips[enAnimationClip_Run].Load("Assets/animData/run.tka");
	animationClips[enAnimationClip_Run].SetLoopFlag(true);
	modelRender.Init("Assets/modelData/unityChan.tkm" , animationClips, enAnimationClip_Num, enModelUpAxisY);

	characterController.Init(25.0f, 75.0f, m_position);

}

Player::~Player() {

}


void Player::Update() {

	Move();

	ManageState();

	PlayAnimation();
	
		Rotation();

		modelRender.Update();
		 
}

void Player::Move() {

	moveSpeed.x  = 0.0f;
	moveSpeed.z = 0.0f;

	Vector3 stickl;
	stickl.x = g_pad[0]->GetLStickXF();
	stickl.y = g_pad[0]->GetLStickYF();

	Vector3 forWard = g_camera3D->GetForward();
	Vector3 right = g_camera3D->GetRight();

	forWard.y = 0.0f;
	right.y = 0.0f;

	forWard.Normalize();
	right.Normalize();

	isDashing = g_pad[0]->IsPress(enButtonB);

	// ˆÚ“®‘¬“x‚ðŒˆ’è
	float movePower = isDashing ? 440.0f : 120.0f;
	Vector3 moveDir = right * stickl.x + forWard * stickl.y;

	moveSpeed.x = moveDir.x * movePower;
	moveSpeed.z = moveDir.z * movePower;


	if (characterController.IsOnGround()) {
		moveSpeed.y = 0.0f;
		jumpCount = 0;
	}
	else
	{
		isGrounded = false;
		moveSpeed.y -= 30.0f;
	}

	if (g_pad[0]->IsTrigger(enButtonA)) {
		if (jumpCount < maxJumpCount) {
			moveSpeed.y = 800.0f;
			jumpCount++;
		}
	}

	m_position = characterController.Execute(moveSpeed, 1.0f / 60.0f);

	
		modelRender.SetPosition(m_position);
}

void Player::Rotation() {
	if (fabsf(moveSpeed.x) >= 0.001f || fabsf(moveSpeed.z) >= 0.001f) {
		rotation.SetRotationYFromDirectionXZ(moveSpeed);
		modelRender.SetRotation(rotation);
	}
}

void Player::ManageState() {
	if (!characterController.IsOnGround()) {
		playerState = 1;
		return;
	}


	if (isDashing&&( fabsf(moveSpeed.x) >= 0.001f || fabsf(moveSpeed.z) >= 0.001f)) {
		playerState = 3; 
	}
	else if (fabsf(moveSpeed.x) >= 0.001f || fabsf(moveSpeed.z) >= 0.001f) {
		playerState=2;
	}
	else {
		playerState = 0;
	}
}


void Player::PlayAnimation() {
	switch (playerState)
	{
	case 0:
		modelRender.PlayAnimation(enAnimationClip_Idle);
		break;
	case 2:
		modelRender.PlayAnimation(enAnimationClip_Walk);
		break;
	case 1:
		modelRender.PlayAnimation(enAnimationClip_Jump);
		break;
	case 3:
		modelRender.PlayAnimation(enAnimationClip_Run);
		break;
	}
}

void Player::Render(RenderContext& rc) {
	modelRender.Draw(rc);
}


