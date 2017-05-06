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
public:
	Player(const char*, const char*);
	~Player();

	void Draw();
private:
	void update();
};

#endif

