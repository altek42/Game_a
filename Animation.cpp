#include "Animation.h"



Animation::Animation(const char* AnimationName, const char* path, int length,const char *fileName, GLuint textureID)
{
	this->name = AnimationName;
	this->lenght = length;
	this->models = new Model*[length];
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

void Animation::Draw(int frame)
{
	float f = (float)frame / 61.0f;
	int n = f*lenght;

	
	//std::cout << "N: " << n <<"Frame: "<<frame<< std::endl;
	models[n]->Draw();
}
