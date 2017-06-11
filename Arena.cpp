#include "Arena.h"



Arena::Arena(const char *modelPath, const char *texturePath):
	GameObject(modelPath,texturePath)
{
	this->collider = new Collider(6.5f, this, ARENA_COLLIDER);
	this->collider->SetPosition(Vector3(-1.5f, 0, -1.5f));
}


Arena::~Arena()
{
	delete this->collider;
}
