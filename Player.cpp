#include "Player.h"


Player::Player(const char *modelPath, const char *texturePath, HealthBar* healthBar) : GameObject(modelPath, texturePath)
{
	delay = 0;
	this->speedWalk = 0.0625;
	this->speedJump = 0.125;

	this->colliderBody = new Collider(0.2f, this, PLAYER_COLLIDER);
	this->colliderSword = new Collider(0.4f, this, SWORD_COLLIDER);

	this->specialVector = new Vector3();
	this->healthBar = healthBar;
	this->specialAction = ACTION_0;
}


Player::~Player()
{
	delete this->colliderBody;
	delete this->colliderSword;
	delete this->specialVector;
}

void Player::Draw()
{
	GameObject::Draw();
}



void Player::FixedUpdate(int frame) {
	GameObject::FixedUpdate(frame);

	this->updateSwordCollider();

	float speed = speedWalk;
	float angle;

	if (this->healthBar->GetHealth() <= 0) {
		Game::GameOver();
	}

	if (this->specialAction != ACTION_0) {
		if (this->specialAction == ACTION_GETTING_HIT) {
			Vector3 dir = Vector3(this->specialVector);
			this->TranslatePosition(dir*speed);
		}
	}

	if (this->delay > 0) {
		this->delay--;
	}
	else {
		this->specialAction = ACTION_0;

		if (Keyboard::GetKey()==KEY_SPACE) {
			speed = speedJump;
		}

		this->SetAnimation("Run");
		if (Keyboard::isPressed('d') && Keyboard::isPressed('s')) {
			speed = speed * DIAG_SPEED_MODIFIER;
			angle = -135;
			this->TranslatePosition(Vector3(speed, 0, speed));
		}
		else if(Keyboard::isPressed('d') && Keyboard::isPressed('w')){
			speed = speed * DIAG_SPEED_MODIFIER;
			angle = -45;
			this->TranslatePosition(Vector3(speed, 0, -speed));
		}
		else if (Keyboard::isPressed('a') && Keyboard::isPressed('s')) {
			speed = speed * DIAG_SPEED_MODIFIER;
			angle = 135;
			this->TranslatePosition(Vector3(-speed, 0, speed));
		}
		else if (Keyboard::isPressed('a') && Keyboard::isPressed('w')) {
			speed = speed * DIAG_SPEED_MODIFIER;
			angle = 45;
			this->TranslatePosition(Vector3(-speed, 0, -speed));
		}
		else if (Keyboard::isPressed('d')) {
			angle = -90;
			this->TranslatePosition(Vector3(speed, 0, 0));
		}
		else if (Keyboard::isPressed('a')) {
			angle = 90;
			this->TranslatePosition(Vector3(-speed, 0, 0));
		}
		else if (Keyboard::isPressed('s')) {
			angle = 180;
			this->TranslatePosition(Vector3(0, 0, speed));
		}
		else if (Keyboard::isPressed('w')) {
			angle = 0;
			this->TranslatePosition(Vector3(0, 0, -speed));
		}
		else {
			angle = this->rotation->GetY();
			this->SetAnimation("no_anim");
		}
		this->SetRotation(Vector3(0, angle, 0));

		if (Keyboard::GetKey() == 'f') {
			this->ResetAnimationFrame();
			this->SetAnimation("Attack");
			this->delay = 41;
			this->specialAction = ACTION_ATTACK;
		}

	}
}

int Player::GetClassID()
{
	return ID_PLAYER_CLASS;
}

void Player::OnCollision(int senderID, GameObject * object)
{
	if (object->GetClassID() == ID_ENEMY_CLASS) {
		if (senderID == PLAYER_COLLIDER) {
			this->GettingHitBy(object);
		}
		if (senderID == SWORD_COLLIDER) {
			this->Hit(object);
		}
	}
	else if (senderID == ARENA_COLLIDER) {
		Vector3 dir = this->position->DirectionTo(object->GetPositionRef());
		dir.SetY(0);
		this->SetSpecialVector(dir*-0.5f);
		this->specialAction = ACTION_GETTING_HIT;
		this->delay = 1;
	}
}

void Player::SetSpecialVector(Vector3 v)
{
	delete this->specialVector;
	this->specialVector = new Vector3(v);
}

void Player::updateSwordCollider()
{
	float angle = this->rotation->GetY();
	float x, z;
	float r = 0.3f;

	if (angle < 1 && angle > -1) {
		x = 0;
		z = -r;
	}
	else if (angle < 181 && angle > 179) {
		x = 0;
		z = r;
	}
	else if (angle < 91 && angle > 89) {
		x = -r;
		z = 0;
	}
	else if (angle > -91 && angle < -89) {
		x = r;
		z = 0;
	}

	else if (angle > -136 && angle < -134) {
		x = r;
		z = r;
	}
	else if (angle > -46 && angle < -44) {
		x = r;
		z = -r;
	}
	else if (angle < 136 && angle > 134) {
		x = -r;
		z = r;
	}
	else if (angle < 46 && angle > 44) {
		x = -r;
		z = -r;
	}
	else {
		x = 1000.0f;
		z = 1000.0f;
	}
	this->colliderSword->SetPosition(Vector3(x,0.0f,z));
}

void Player::GettingHitBy(GameObject * object)
{
	int action = 0;
	Enemy* e = dynamic_cast <Enemy*>(object);
	if (e != 0) {
		action = e->GetSpecialAction();
	}

	if (action != ACITON_E_DIE) {
		Vector3 dir = this->position->DirectionTo(object->GetPositionRef());
		this->SetSpecialVector(dir);
		this->specialAction = ACTION_GETTING_HIT;
		this->delay = 12;
		this->healthBar->Decrease();
	}
}

void Player::Hit(GameObject * object)
{
	if (this->specialAction == ACTION_ATTACK) {
		Enemy* e = dynamic_cast <Enemy*>(object);
		if (e != 0) {
			e->GettingHit();
		}
	}
}
