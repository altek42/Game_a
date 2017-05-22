#ifndef COLLIDER_CLASS_H
#define COLLIDER_CLASS_H

#include "Vector3.h"
#include "GameObject.h"
class GameObject;
class Collider
{
	float radius;
	Vector3* position;
	GameObject* parent;

	void(*OnCollision)(GameObject* object);
public:
	Collider(float radius, GameObject* parent, void(*func)(GameObject* object));
	~Collider();

	float GetRadius();
	Vector3 GetPosition();
	GameObject* GetParent();

	void CheckCollisionWith(Collider* c);
};

#endif