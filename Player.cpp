#include "Player.h"


Player::Player(const char *modelPath, const char *texturePath) : GameObject(modelPath, texturePath)
{
	delay = 0;
	this->speedWalk = 0.0625;
	this->speedJump = 0.125;

	this->colliderBody = new Collider(0.2f, this);
	this->specialVector = new Vector3();
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

	float speed = speedWalk;
	float angle;

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
			angle = -135;
			this->TranslatePosition(Vector3(speed, 0, speed));
		}
		else if(Keyboard::isPressed('d') && Keyboard::isPressed('w')){
			angle = -45;
			this->TranslatePosition(Vector3(speed, 0, -speed));
		}
		else if (Keyboard::isPressed('a') && Keyboard::isPressed('s')) {
			angle = 135;
			this->TranslatePosition(Vector3(-speed, 0, speed));
		}
		else if (Keyboard::isPressed('a') && Keyboard::isPressed('w')) {
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
		}

	}
}

int Player::GetClassID()
{
	return ID_PLAYER_CLASS;
}

void Player::OnCollision(GameObject * object)
{
	if (object->GetClassID() == ID_ENEMY_CLASS) {
		Vector3 dir = this->position->DirectionTo(object->GetPositionRef());
		this->SetSpecialVector(dir);
		this->specialAction = ACTION_GETTING_HIT;
		this->delay = 12;
	}
}

void Player::SetSpecialVector(Vector3 v)
{
	delete this->specialVector;
	this->specialVector = new Vector3(v);
}
