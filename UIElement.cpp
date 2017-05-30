#include "TextPlane.h"



UIElement::UIElement(const char* mp, const char* tp) : GameObject(mp,tp)
{

}


UIElement::~UIElement()
{
}

void UIElement::Draw()
{
	this->SetPosition(Camera::GetPosition());
	this->TranslatePosition(Vector3(-0.15, -0.15, -0.15));

	GameObject::Draw();
}

void UIElement::FixedUpdate(int frame)
{
	if (Keyboard::isPressed('r')) {
		//restart
	}
}