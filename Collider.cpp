#include "Collider.h"



Collider::Collider(float radius, GameObject * parent, void(*func)(GameObject *object))
{
	this->radius = radius;
	this->parent = parent;
	this->OnCollision = func;
}

Collider::~Collider()
{
}

Vector3 Collider::GetPosition()
{
	return Vector3(this->position);
}

float Collider::GetRadius()
{
	return this->radius;
}

GameObject * Collider::GetParent()
{
	return this->parent;
}

void Collider::CheckCollisionWith(Collider * c)
{
	if (this->OnCollision != NULL) {
		Vector3 v = Vector3(this->position) - c->GetPosition();
		float distance = v.GetLenght();
		if (distance <= (this->radius + c->radius) ){
			OnCollision(c->parent);
		}
	}
}
