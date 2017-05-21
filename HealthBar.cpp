#include "HealthBar.h"



HealthBar::HealthBar(const char* modelPath, int count, GLuint* texturesID)
	: GameObject(modelPath)
{
	this->maxHealth = count;
	this->actualHealth = count;
	this->textures = new GLuint[count];
	for (int i = 0; i < count; i++)
	{
		this->textures[i] = texturesID[i];
	}
}


HealthBar::~HealthBar()
{
	delete this->textures;
}
