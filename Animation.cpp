#include "Animation.h"


Animation::Animation(const char* AnimationName, const char* path, int length,const char *fileName, GameObject* parent)
{
	this->parent = parent;
	this->SetAnimatinTime(61);
	this->name = AnimationName;
	this->length = length;
	this->models = new Model*[length];
	this->frameOffset = this->calcFrameOffset();

	for (int i = 0; i < length; i++)
	{
		char p[500];
		strcpy(p, path);
		strcat(p, "\\");
		strcat(p, fileName);
		strcat(p, "_0000");
		if (length >= 100) {
			//errr
		}

		if (i < 10) {
			strcat(p, "0");
			char liczba[3];
			_itoa(i, liczba,10);
			strcat(p, liczba);
		}
		else if (i < 100) {
			char liczba[3];
			_itoa(i, liczba, 10);
			strcat(p, liczba);
		}
		strcat(p, ".obj");

		models[i] = new Model(p);
		models[i]->SetTextureID(parent->GetTextureID());
	}
	
}

Animation::Animation(Animation *a, GameObject* p)
{
	this->parent = p;
	this->animationTime = a->animationTime;

	this->name = a->name;
	this->length = a->length;
	this->models = a->models;
	this->frameOffset = this->calcFrameOffset();
}


Animation::~Animation()
{	
	for (int i = 0; i < length; i++)
	{
		delete models[i];
	}
	delete[] models;
}

const char * Animation::GetName()
{
	return this->name;
}

void Animation::SetAnimatinTime(int frameLenght)
{
	this->animationTime = frameLenght;
}

void Animation::Draw()
{
	models[this->parent->GetAnimationFrame()]->Draw();
}

void Animation::FixedUpdate(int frame)
{
	if (this->frameOffset < 0) {
		this->parent->IncAnimationFrame();
		this->frameOffset = this->calcFrameOffset();

		if (this->parent->GetAnimationFrame() >= this->length) {
			this->parent->ResetAnimationFrame();
		}
	}
	this->frameOffset--;
}

int Animation::calcFrameOffset()
{
	return ((this->animationTime+1) / this->length);
}
