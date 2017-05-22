#include "Enemy.h"



Enemy::Enemy(const char*modelPath, const char*texturePath, GameObject* player) : GameObject(modelPath, texturePath)
{
	this->player = player;
	this->speed = 0.02;

	this->colliderBody = new Collider(1.0f, this);
}


Enemy::~Enemy()
{
}

void Enemy::FixedUpdate(int frame) {
	GameObject::FixedUpdate(frame);
	Vector3 dir = this->position->DirectionTo(this->player->GetPositionRef());

	float angle = dir.GetX() * 90 * -1 ;
	angle = (dir.GetZ() > 0) ? -1* angle+180 : angle;
	this->SetRotation(Vector3(0, angle, 0));

	this->TranslatePosition(dir * -speed);
}