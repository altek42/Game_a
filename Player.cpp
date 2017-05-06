#include "Player.h"



Player::Player(const char *modelPath, const char *texturePath) : GameObject(modelPath, texturePath)
{
	this->speedWalk = 0.008;
	this->speedJump = 0.02;
}


Player::~Player()
{
}

void Player::Draw()
{
	this->update();
	GameObject::Draw();
}

void Player::update() {
	float speed = speedWalk;
	if (Keyboard::GetKey()==KEY_SPACE) {
		speed = speedJump;
	}

	if (Keyboard::isPressed('d')) {
		this->TranslatePosition(Vector3(speed, 0, 0));
	}
	else if (Keyboard::isPressed('a')) {
		this->TranslatePosition(Vector3(-speed, 0, 0));
	}
	if (Keyboard::isPressed('s')) {
		this->TranslatePosition(Vector3(0, 0, speed));
	}
	else if (Keyboard::isPressed('w')) {
		this->TranslatePosition(Vector3(0, 0, -speed));
	}

}
