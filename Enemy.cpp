#include "Enemy.h"



Enemy::Enemy(const char*modelPath, const char*texturePath, GameObject* player) : GameObject(modelPath, texturePath)
{
	this->player = player;
}


Enemy::~Enemy()
{
}

void Enemy::FixedUpdate(int frame) {
	GameObject::FixedUpdate(frame);

}