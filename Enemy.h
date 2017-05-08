#pragma once
#include "GameObject.h"
class Enemy :
	public GameObject
{
public:
	GameObject * player;

	Enemy(const char*, const char*,GameObject*);
	~Enemy();

	void FixedUpdate(int);
};

