#include "TextPlane.h"



TextPlane::TextPlane(const char* mp, const char* tp) : GameObject(mp,tp)
{

}


TextPlane::~TextPlane()
{
}

void TextPlane::Draw()
{
	this->SetPosition(Camera::GetPosition());
	this->TranslatePosition(Vector3(-0.2, -0.2, -0.2));

	GameObject::Draw();
}

void TextPlane::FixedUpdate(int frame)
{
	if (Keyboard::isPressed('r')) {
		//restart
	}
}