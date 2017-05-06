#ifndef ANIMATION_CLASS_H
#define ANIMATION_CLASS_H
#include "Model.h"
#include "Texture.h"
#include <string>
#include <cstdlib>
class Animation
{
	int lenght;
	Model** models;

public:
	Animation(const char*,int, const char*, GLuint);
	~Animation();
};


#endif