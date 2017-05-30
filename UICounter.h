#ifndef UI_COUNTER_CLASS_H
#define UI_COUNTER_CLASS_H
#define _CRT_SECURE_NO_WARNINGS
#include "UIElement.h"
#include "Texture.h"

class UICounter :
	public UIElement
{
	GLuint* numbers;
	int count;
	int pointer;
public:
	UICounter(const char* mp, const char* tp, const char* tname,int count);
	~UICounter();

	void Draw();
	void FixedUpdate(int);
};

#endif