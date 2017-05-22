#ifndef PLAYER_CLASS_H
#define PLAYER_CLASS_H

#include "GameObject.h"
#include "Keyboard.h"
#include "Collider.h"

class Player :
	public GameObject
{
private:
	float speedWalk;
	float speedJump;
	int delay;

	Collider* colliderBody;
	Collider* colliderSword;

public:
	Player(const char*, const char*);
	~Player();


	void Draw();
	void FixedUpdate(int);
private:
	void OnCollision(GameObject* object);
};

#endif

