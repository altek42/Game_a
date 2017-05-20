#include "Enemy.h"



Enemy::Enemy(const char*modelPath, const char*texturePath, GameObject* player) : GameObject(modelPath, texturePath)
{
	this->player = player;
	this->speed = 0.02;
}


Enemy::~Enemy()
{
}

void Enemy::FixedUpdate(int frame) {
	GameObject::FixedUpdate(frame);
	Vector3 dir = this->position->DirectionTo(this->player->GetPositionRef());

	float angle;
	std::cout << dir << std::endl;
	
	if (dir.GetX()>0 && dir.GetZ()>0) {
		angle = -135;
	}
	else if (dir.GetX()>0 && dir.GetZ()<0) {
		angle = -45;
	}
	else if (dir.GetX()<0 && dir.GetZ()>0) {
		angle = 135;
	}
	else if (dir.GetX()<0 && dir.GetZ()<0) {
		angle = 45;
	}
	else if (dir.GetX()>0) {
		angle = -90;
	}
	else if (dir.GetX()<0) {
		angle = 90;
	}
	else if (dir.GetZ()>0) {
		angle = 180;
	}
	else if (dir.GetZ()<0) {
		angle = 0;
	}
	else {
		angle = this->rotation->GetY();
	}
	this->SetRotation(Vector3(0, angle, 0));

	this->TranslatePosition(dir * -speed);
}