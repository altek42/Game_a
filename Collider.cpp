#include "Collider.h"

std::vector <Collider*> Collider::colliderList;


Collider::Collider(float radius, GameObject * parent)
{
	this->radius = radius;
	this->parent = parent;
	colliderList.push_back(this);
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
	Vector3 v = Vector3(this->position) - c->GetPosition();
	float distance = v.GetLenght();
	if (distance <= (this->radius + c->radius) ){
		this->parent->OnCollision(c->parent);
	}
}

void Collider::CheckCollisions()
{
	for (size_t i = 0; i < colliderList.size(); i++)
	{
		for (size_t j = 0; j < colliderList.size(); j++)
		{
			if (i == j) {
				continue;
			}
			colliderList[i]->CheckCollisionWith(colliderList[j]);
		}
	}
}
