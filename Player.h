#ifndef PLAYER_CLASS_H
#define PLAYER_CLASS_H

#include "GameObject.h"
#include "Keyboard.h"
#include "Collider.h"

#define ACTION_0 0
#define ACTION_GETTING_HIT 1

class Player :
	public GameObject
{
private:
	float speedWalk;
	float speedJump;
	int delay;
	int specialAction;
	Vector3* specialVector;

	Collider* colliderBody;
	Collider* colliderSword;

public:
	Player(const char*, const char*);
	~Player();


	void Draw();
	void FixedUpdate(int);

	int GetClassID();
private:
	void OnCollision(GameObject* object);
	void SetSpecialVector(Vector3 v);
};

#endif

