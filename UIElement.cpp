#include "UIElement.h"



UIElement::UIElement(const char* mp, const char* tp) : GameObject(mp,tp)
{
	this->SetRotation(Vector3(0, 45, 0));
	this->localPos = new Vector3();
}

UIElement::UIElement(const char * mp) : UIElement(mp,NULL)
{
}


UIElement::~UIElement()
{
	delete this->localPos;
}

void UIElement::SetLocalPosition(const Vector3 & v)
{
	delete this->localPos;
	this->localPos = new Vector3(v);
}

void UIElement::Draw()
{
	this->SetPosition(Camera::GetPosition());
	this->TranslatePosition(Vector3(-0.15, -0.15, -0.15));
	this->TranslatePosition(Vector3(this->localPos));

	GameObject::Draw();
}

void UIElement::FixedUpdate(int frame)
{
	/*if (Keyboard::isPressed('r')) {
		//restart
	}*/
}