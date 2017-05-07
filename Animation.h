#ifndef ANIMATION_CLASS_H
#define ANIMATION_CLASS_H
#include "Model.h"
#include "Texture.h"
#include <string>
#include <cstdlib>
#include <iostream>

class Animation
{
	static int frameToShow;

	const char* name;
	int lenght;
	int frameOffset;
	Model** models;

	int animationTime;
public:
	static void RestartAnimation();
	
	Animation(const char*,const char*,int, const char*, GLuint);
	~Animation();

	const char* GetName();
	void SetAnimatinTime(int frameLenght);

	void Draw();
	void FixedUpdate(int);
private:
	int calcFrameOffset();

};


#endif