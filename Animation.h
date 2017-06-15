#ifndef ANIMATION_CLASS_H
#define ANIMATION_CLASS_H
#define _CRT_SECURE_NO_WARNINGS
#include "GameObject.h"
#include "Model.h"
#include "Texture.h"
#include <string>
#include <cstdlib>
#include <iostream>


class GameObject;
class Animation
{
	const char* name;
	int length;
	int frameOffset;
	Model** models;

	GameObject* parent;

	int animationTime;
public:
	Animation(const char*,const char*,int, const char*, GameObject*);
	Animation(Animation*, GameObject* parent);
	~Animation();

	const char* GetName();
	void SetAnimatinTime(int frameLenght);

	void Draw();
	void FixedUpdate(int);
private:
	int calcFrameOffset();

};


#endif