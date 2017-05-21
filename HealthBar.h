#ifndef HEALTH_BAR_CLASS_H
#define HEALTH_BAR_CLASS_H
#include "GameObject.h"
class HealthBar :
	public GameObject
{
	int maxHealth;
	int actualHealth;
	GLuint* textures;
public:
	HealthBar(const char* modelPath, int count, GLuint* texturesID);
	~HealthBar();
};

#endif