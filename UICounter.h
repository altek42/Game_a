#ifndef UI_COUNTER_CLASS_H
#define UI_COUNTER_CLASS_H
#define _CRT_SECURE_NO_WARNINGS
#include "UIElement.h"
#include "Texture.h"

class UICounter :
	public UIElement
{
	static UICounter* _instance;

	GLuint* numbers;
	int count;
	int pointer;

	UICounter(const char* mp, const char* tp, const char* tname,int count);
	~UICounter();
public:
	static void CreateInstance(const char* mp, const char* tp, const char* tname, int count);
	static void DestroyInstance();
	static UICounter* GetInstance();

	void Increment();

	void Draw();
	void FixedUpdate(int);
};

#endif