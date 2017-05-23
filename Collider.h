#ifndef COLLIDER_CLASS_H
#define COLLIDER_CLASS_H

#include <vector>
#include "Vector3.h"
#include "GameObject.h"
class GameObject;
class Collider
{
	static std::vector <Collider*> colliderList;

	float radius;
	Vector3* position;
	GameObject* parent;

public:
	Collider(float radius, GameObject* parent);
	~Collider();

	float GetRadius();
	Vector3 GetPosition();
	Vector3 GetPosition2();
	GameObject* GetParent();

	void SetPosition(Vector3 v);

	void CheckCollisionWith(Collider* c);
	
	static void CheckCollisions();
};

#endif