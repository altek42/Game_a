#ifndef COLLIDER_CLASS_H
#define COLLIDER_CLASS_H

#include <vector>
#include "Vector3.h"
#include "GameObject.h"

#define SWORD_COLLIDER 1
#define PLAYER_COLLIDER 2
#define ENEMY_COLLIDER 3

class GameObject;
class Collider
{
	static std::vector <Collider*> colliderList;

	float radius;
	Vector3* position;
	GameObject* parent;
	int ID;
public:
	Collider(float radius, GameObject* parent);
	Collider(float radius, GameObject* parent, int id);
	~Collider();

	float GetRadius();
	Vector3 GetPosition();
	Vector3 GetPosition2();
	GameObject* GetParent();
	int GetID();

	void SetPosition(Vector3 v);
	void SetID(int x);

	void CheckCollisionWith(Collider* c);
	
	static void CheckCollisions();
};

#endif