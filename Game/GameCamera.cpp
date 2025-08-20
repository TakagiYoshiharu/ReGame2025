#include "stdafx.h"
#include "GameCamera.h"
#include"Player.h"



GameCamera::GameCamera()
{
	g_camera3D->SetNear(0.1f);

	g_camera3D->SetFar(10000.0f);

	player = FindGO<Player>("BattleCharacter");
}


void GameCamera::Update() {
	Vector3 target;

	target.x = player->m_position.x;
	target.y = player->m_position.y + 100.0f;
	target.z = player->m_position.z;
	g_camera3D->SetTarget(target);

	Vector3 cameraPos;
	cameraPos = target;

	cameraPos. z -= 300.0f;
	g_camera3D->SetPosition(cameraPos);
	
	//g_camera3D->SetNear(1.0f);

	//g_camera3D->SetFar(5000.0f);

	float angle = g_camera3D->GetViewAngle();
	
}
