#include "Collider.h"

std::vector <Collider*> Collider::colliderList;


Collider::Collider(float radius, GameObject * parent) : Collider(radius, parent, 0)
{

}

Collider::Collider(float radius, GameObject * parent, int id)
{
	this->ID = id;
	this->radius = radius;
	this->parent = parent;
	this->position = new Vector3();
	Collider::colliderList.push_back(this);
}

Collider::~Collider()
{
	delete this->position;
}

Vector3 Collider::GetPosition()
{
	return Vector3(this->position);
}

Vector3 Collider::GetPosition2()
{
	Vector3* pv = this->parent->GetPositionRef();
	return Vector3(this->position) + Vector3(pv);
}

float Collider::GetRadius()
{
	return this->radius;
}

GameObject * Collider::GetParent()
{
	return this->parent;
}

int Collider::GetID()
{
	return this->ID;
}

void Collider::SetPosition(Vector3 v)
{
	delete position;
	this->position = new Vector3(v);
}

void Collider::SetID(int x)
{
	this->ID = x;
}

void Collider::CheckCollisionWith(Collider * c)
{
	if (this->ID == ARENA_COLLIDER || c->GetID() == ARENA_COLLIDER) {
		if (this->ID == ARENA_COLLIDER && c->ID == PLAYER_COLLIDER) {
			Vector3 v = c->GetPosition2();
			float xL = v.GetX() - c->radius + this->GetPosition2().GetX();
			float xR = v.GetX() + c->radius + this->GetPosition2().GetX();
			float zU = v.GetZ() - c->radius + this->GetPosition2().GetZ();
			float zD = v.GetZ() + c->radius + this->GetPosition2().GetZ();
			if (xL < -this->radius) {
				c->GetParent()->OnCollision(this->ID, this->parent);
			}
			else if (xR > this->radius) {
				c->GetParent()->OnCollision(this->ID, this->parent);
			}
			else if (zU < -this->radius) {
				c->GetParent()->OnCollision(this->ID, this->parent);
			}
			else if (zD > this->radius) {
				c->GetParent()->OnCollision(this->ID, this->parent);
			}
		}
	}
	else {
		Vector3 v = (this->GetPosition2() ) - c->GetPosition2();
	
		float distance = v.GetLenght();
		float r = this->radius + c->radius;
		if (distance < r) {
			this->parent->OnCollision(this->GetID(), c->parent);
			/*std::cout << "Distance:" << distance << std::ends;
			std::cout << "\tRad:" << r << std::ends;
			std::cout << "\tID:" << this->ID << std::ends;
			std::cout << "\tParent:" << this->parent->GetName() << std::endl;*/
		}
	}
}

void Collider::CheckCollisions()
{
	for (size_t i = 0; i < colliderList.size(); i++)
	{
		for (size_t j = 0; j < colliderList.size(); j++)
		{
			if (i != j) {
				if (colliderList[i]->GetParent() != colliderList[j]->GetParent()) {
					colliderList[i]->CheckCollisionWith(colliderList[j]);
				}
			}
		}
	}
}
