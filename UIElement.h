#ifndef TEXT_PLANE_CLASS_H
#define TEXT_PLANE_CLASS_H

#include "GameObject.h"
#include "Camera.h"
#include "Keyboard.h"

class UIElement :
	public GameObject
{
public:
	UIElement(const char* mp, const char* tp);
	~UIElement();

	void Draw();
	void FixedUpdate(int);
};

#endif