#ifndef TEXT_PLANE_CLASS_H
#define TEXT_PLANE_CLASS_H

#include "GameObject.h"
#include "Camera.h"
#include "Keyboard.h"

class UIElement :
	public GameObject
{
	Vector3* localPos;
public:
	UIElement(const char* mp, const char* tp);
	UIElement(const char* mp);
	~UIElement();

	void SetLocalPosition(const Vector3&);

	virtual void Draw();
	virtual void FixedUpdate(int);
};

#endif