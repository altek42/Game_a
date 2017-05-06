#include "Player.h"



Player::Player(const char *modelPath, const char *texturePath) : GameObject(modelPath, texturePath)
{
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
	/*if (Keyboard::GetKey()==KEY_SPACE) {
		speed = speedJump;
	}*/


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
