#ifndef ENEMY_CLASS_H
#define ENEMY_CLASS_H
#include <iostream>
#include "GameObject.h"
#include "UICounter.h"

#define ACTION_E_0 0
#define ACTION_E_GETTING_HIT 1
#define ACTION_E_COLLISION_WITH_E 2
#define ACITON_E_DIE 3

class Enemy :
	public GameObject
{
	float speed;
	int delay;
	int specialAction;
	Vector3* specialVector;

	int countSpawns;
	Vector3* spawns;
public:
	GameObject * player;
	Collider* colliderBody;

	Enemy(const char*, const char*,GameObject*);
	Enemy(Enemy*);
	~Enemy();

	void FixedUpdate(int);

	int GetClassID();
	int GetSpecialAction();

	void GettingHit();
private:
	void SetRandSpeed();
	void Respawn();

	void OnCollision(int senderID, GameObject* object);
	void SetSpecialVector(Vector3 v);

};

#endif