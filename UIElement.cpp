#include "UIElement.h"



UIElement::UIElement(const char* mp, const char* tp) : GameObject(mp,tp)
{
	this->SetRotation(Vector3(0, 45, 0));
}

UIElement::UIElement(const char * mp) : UIElement(mp,NULL)
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
	/*if (Keyboard::isPressed('r')) {
		//restart
	}*/
}