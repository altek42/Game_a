#ifndef PLAYER_CLASS_H
#define PLAYER_CLASS_H

#include "GameObject.h"
#include "Keyboard.h"

class Player :
	public GameObject
{
private:
	float speedWalk;
	float speedJump;
	//bool isAction;
	int delay;
public:
	Player(const char*, const char*);
	~Player();

	void Draw();
	void FixedUpdate(int);
private:
};

#endif

