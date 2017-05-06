#ifndef ANIMATION_CLASS_H
#define ANIMATION_CLASS_H
#include "Model.h"
#include "Texture.h"
#include <string>
#include <cstdlib>
#include <iostream>

class Animation
{
	const char* name;
	int lenght;
	Model** models;

public:
	Animation(const char*,const char*,int, const char*, GLuint);
	~Animation();

	const char* GetName();

	void Draw(int);
};


#endif