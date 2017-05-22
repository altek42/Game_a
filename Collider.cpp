#include "Collider.h"

std::vector <Collider*> Collider::colliderList;


Collider::Collider(float radius, GameObject * parent)
{
	this->radius = radius;
	this->parent = parent;
	this->position = new Vector3();
	colliderList.push_back(this);
}

Collider::~Collider()
{
	delete this->position;
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

void Collider::SetPosition(Vector3 v)
{
	delete position;
	this->position = new Vector3(v);
}

void Collider::CheckCollisionWith(Collider * c)
{
	Vector3* pv = this->parent->GetPositionRef();
	Vector3 v = (Vector3(this->position) + Vector3(pv) ) - c->GetPosition();
	float distance = v.GetLenght();
	if (distance <= (this->radius + c->radius)) {
		this->parent->OnCollision(c->parent);
	}
}

void Collider::CheckCollisions()
{
	for (size_t i = 0; i < colliderList.size(); i++)
	{
		for (size_t j = 0; j < colliderList.size(); j++)
		{
			if (i != j) {
				colliderList[i]->CheckCollisionWith(colliderList[j]);
			}
		}
	}
}
