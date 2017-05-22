#ifndef ENEMY_CLASS_H
#define ENEMY_CLASS_H
#include <iostream>
#include "GameObject.h"
class Enemy :
	public GameObject
{
	float speed;
public:
	GameObject * player;
	Collider* colliderBody;

	Enemy(const char*, const char*,GameObject*);
	~Enemy();

	void FixedUpdate(int);
private:
};

#endif