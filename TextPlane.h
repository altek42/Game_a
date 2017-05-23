#ifndef TEXT_PLANE_CLASS_H
#define TEXT_PLANE_CLASS_H

#include "GameObject.h"
#include "Camera.h"

class TextPlane :
	public GameObject
{
public:
	TextPlane(const char* mp, const char* tp);
	~TextPlane();

	void Draw();
	void FixedUpdate(int);
};

#endif