#ifndef ARENA_CLASS_H
#define ARENA_CLASS_H
#include "GameObject.h"
#include "Collider.h"

class Arena :
	public GameObject
{
	Collider* collider;
public:
	Arena(const char *modelPath, const char *texturePath);
	~Arena();
};

#endif