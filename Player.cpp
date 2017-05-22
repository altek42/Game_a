#include "Player.h"


Player::Player(const char *modelPath, const char *texturePath) : GameObject(modelPath, texturePath)
{
	delay = 0;
	this->speedWalk = 0.0625;
	this->speedJump = 0.125;

	this->colliderBody = new Collider(2.0f, this);
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
	float angle;

	if (this->delay > 0) {
		this->delay--;
	}
	else {
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

void Player::OnCollision(GameObject * object)
{
	std::cout << "Collision " << this->GetName() << " : " << object->GetName() << std::endl;
}