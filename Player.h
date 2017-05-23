#ifndef PLAYER_CLASS_H
#define PLAYER_CLASS_H

#include "GameObject.h"
#include "Keyboard.h"
#include "Collider.h"
#include "HealthBar.h"
#include "Game.h"

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

	HealthBar* healthBar;
public:
	Player(const char* mp, const char* tp, HealthBar* h);
	~Player();


	void Draw();
	void FixedUpdate(int);

	int GetClassID();
private:
	void OnCollision(GameObject* object);
	void SetSpecialVector(Vector3 v);

	void GettingHitBy(GameObject* object);
};

#endif

