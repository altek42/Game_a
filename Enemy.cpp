#include "Enemy.h"



Enemy::Enemy(const char*modelPath, const char*texturePath, GameObject* player) : GameObject(modelPath, texturePath)
{
	this->player = player;

	this->SetRandSpeed();

	this->colliderBody = new Collider(0.2f, this);
	this->specialVector = new Vector3();
	this->specialAction = ACTION_E_0;

	countSpawns = 4;
	this->spawns = new Vector3[countSpawns];
	this->spawns[0] = Vector3(1.3f, 0, -6.0f);
	this->spawns[1] = Vector3(-6.0f, 0, 1.3);
	this->spawns[2] = Vector3(9.0f, 0, 0);
	this->spawns[3] = Vector3(1.3f, 0, 9.0f);
}

Enemy::Enemy(Enemy * e) : GameObject(e)
{
	this->player = e->player;
	this->SetRandSpeed();

	this->colliderBody = new Collider(0.2f, this);
	this->specialVector = new Vector3();
	this->specialAction = ACTION_E_0;

	this->countSpawns = e->countSpawns;
	this->spawns = e->spawns;
}


Enemy::~Enemy()
{
	delete this->colliderBody;
	delete this->specialVector;
	delete[] this->spawns;
}

void Enemy::FixedUpdate(int frame) {
	GameObject::FixedUpdate(frame);

	if (this->specialAction != ACTION_E_0) {
		if (this->specialAction == ACTION_E_COLLISION_WITH_E) {
			Vector3 dir = Vector3(this->specialVector);
			float r = (rand()%5) *0.000001f;
			this->TranslatePosition(Vector3(r, 0, r));
			this->TranslatePosition(dir*2*speed);
		}
	}

	if (this->delay > 0) {
		this->delay--;
	}
	else {
		if (this->specialAction == ACITON_E_DIE) {
			this->Respawn();
		}
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

int Enemy::GetSpecialAction()
{
	return this->specialAction;
}

void Enemy::GettingHit()
{
	this->delay = 58;
	this->specialAction = ACITON_E_DIE;
	this->ResetAnimationFrame();
	this->SetAnimation("Die");
	//animacja umierania
	std::cout << "I " << this->name << " want to die." << std::endl;
}

void Enemy::SetRandSpeed()
{
	float r = ((rand() % 5) + 1) * 0.01;
	this->speed = r;
}

void Enemy::Respawn()
{
	int r = rand() % 4;
	this->SetPosition(this->spawns[r]);
	this->SetAnimation("Jump");
	this->SetRandSpeed();
}

void Enemy::OnCollision(int senderID, GameObject * object)
{
	if (object->GetClassID() == ID_ENEMY_CLASS) {
		if (this->specialAction == ACTION_E_0) {
			Vector3 dir = this->position->DirectionTo(object->GetPositionRef());
			this->SetSpecialVector(dir);
			this->specialAction = ACTION_E_COLLISION_WITH_E;
			this->delay = 12;
		}
	}
}

void Enemy::SetSpecialVector(Vector3 v)
{
	delete this->specialVector;
	this->specialVector = new Vector3(v);
}
