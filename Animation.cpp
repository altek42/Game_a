#include "Animation.h"

int Animation::frameToShow = 0;

void Animation::RestartAnimation()
{
	Animation::frameToShow = 0;
}

Animation::Animation(const char* AnimationName, const char* path, int length,const char *fileName, GLuint textureID)
{
	this->SetAnimatinTime(61);
	this->name = AnimationName;
	this->lenght = length;
	this->models = new Model*[length];
	this->frameOffset = this->calcFrameOffset();
	//name_000000

	for (int i = 0; i < length; i++)
	{
		char p[500];
		strcpy(p, path);
		strcat(p, "\\");
		strcat(p, fileName);
		strcat(p, "_0000");
		if (lenght >= 100) {
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
		models[i]->SetTextureID(textureID);
	}
	
}


Animation::~Animation()
{
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
	
	/*float f = (float)frame / 61.0f;
	int n = f*lenght;*/

	//std::cout << "N: " << frameToShow <<"Frame: "<<frame<< std::endl;
	
	models[Animation::frameToShow]->Draw();
}

void Animation::FixedUpdate(int frame)
{
	if (this->frameOffset < 0) {
		Animation::frameToShow++;
		this->frameOffset = this->calcFrameOffset();

		if (Animation::frameToShow >= this->lenght) {
			Animation::frameToShow = 0;
		}
	}
	this->frameOffset--;
}

int Animation::calcFrameOffset()
{
	return ((this->animationTime+1) / this->lenght);
}
