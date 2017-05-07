#include "Player.h"



Player::Player(const char *modelPath, const char *texturePath) : GameObject(modelPath, texturePath)
{
	delay = 0;
	this->speedWalk = 0.0625;
	this->speedJump = 0.125;
}


Player::~Player()
{
}

void Player::Draw()
{
	GameObject::Draw();
}



void Player::FixedUpdate(int frame) {
	GameObject::FixedUpdate(frame);

	float speed = speedWalk;

	if (this->delay > 0) {
		this->delay--;
	}
	else {
		if (Keyboard::GetKey()==KEY_SPACE) {
			speed = speedJump;
		}

		this->SetAnimation("no_anim");
		if (Keyboard::isPressed('d')) {
			this->TranslatePosition(Vector3(speed, 0, 0));
			this->SetAnimation("Run");
		}
		else if (Keyboard::isPressed('a')) {
			this->TranslatePosition(Vector3(-speed, 0, 0));
			this->SetAnimation("Run");
		}
		if (Keyboard::isPressed('s')) {
			this->TranslatePosition(Vector3(0, 0, speed));
			this->SetAnimation("Run");
		}
		else if (Keyboard::isPressed('w')) {
			this->TranslatePosition(Vector3(0, 0, -speed));
			this->SetAnimation("Run");
		}

		if (Keyboard::GetKey() == 'f') {
			Animation::RestartAnimation();
			this->SetAnimation("Attack");
			this->delay = 20;
		}

	}
}
