#include "Enemy.h"



Enemy::Enemy(const char*modelPath, const char*texturePath, GameObject* player) : GameObject(modelPath, texturePath)
{
	this->player = player;
	this->speed = 0.02;

	this->colliderBody = new Collider(0.2f, this);
	this->specialVector = new Vector3();
}


Enemy::~Enemy()
{
	delete this->colliderBody;
	delete this->specialVector;
}

void Enemy::FixedUpdate(int frame) {
	GameObject::FixedUpdate(frame);

	if (this->specialAction != ACTION_E_0) {
		if (this->specialAction == ACTION_E_COLLISION_WITH_E) {
			Vector3 dir = Vector3(this->specialVector);
			this->TranslatePosition(dir*speed);
		}
	}

	if (this->delay > 0) {
		this->delay--;
	}
	else {
		this->specialAction = ACTION_E_0;

		Vector3 dir = this->position->DirectionTo(this->player->GetPositionRef());

		float angle = dir.GetX() * 90 * -1;
		angle = (dir.GetZ() > 0) ? -1 * angle + 180 : angle;
		this->SetRotation(Vector3(0, angle, 0));

		this->TranslatePosition(dir * -speed);
	}
}

int Enemy::GetClassID()
{
	return ID_ENEMY_CLASS;
}

void Enemy::OnCollision(GameObject * object)
{
	if (object->GetClassID() == ID_ENEMY_CLASS) {
		Vector3 dir = this->position->DirectionTo(object->GetPositionRef());
		this->SetSpecialVector(dir);
		this->specialAction = ACTION_E_COLLISION_WITH_E;
		this->delay = 12;
	}
}

void Enemy::SetSpecialVector(Vector3 v)
{
	delete this->specialVector;
	this->specialVector = new Vector3(v);
}
