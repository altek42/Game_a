#include "Camera.h"
Vector3* Camera::Position = new Vector3(0, 0, 0);
Vector3* Camera::Up = new Vector3(0, 1, 0);
GameObject* Camera::Target;

Camera::Camera()
{
}

Camera::~Camera()
{
}

void Camera::Delete()
{
	delete Position;
	delete Up;
}

void Camera::SetPosition(const Vector3 & v)
{
	delete Position;
	Position = new Vector3(v);
}

void Camera::SetTarget(GameObject * target)
{
	Target = target;
}

void Camera::SetUp(const Vector3 & v)
{
	delete Up;
	Up = new Vector3(v);
}

void Camera::TranslatePosition(const Vector3 & v)
{
	Vector3 vec(Position);
	vec = vec + v;
	std::cout <<"Vec: "<< vec << std::endl;
	SetPosition(vec);
}

void Camera::Draw(){
	if (Target != NULL) {
		gluLookAt(
			Position->GetX() + Target->GetPositionRef()->GetX(),
			Position->GetY() + Target->GetPositionRef()->GetY(),
			Position->GetZ() + Target->GetPositionRef()->GetZ(), // Pozycja kamery
			Target->GetPositionRef()->GetX() ,
			Target->GetPositionRef()->GetY() ,
			Target->GetPositionRef()->GetZ() , // Punkt na ktory patrzy kamera (pozycja + kierunek)
			Up->GetX(), Up->GetY(), Up->GetZ() // Wektor wyznaczajacy pion
			);
	}
}