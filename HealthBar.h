#ifndef HEALTH_BAR_CLASS_H
#define HEALTH_BAR_CLASS_H
#include "GameObject.h"
#include "Camera.h"
class HealthBar :
	public GameObject
{
	int maxHealth;
	int actualHealth;
	GLuint* textures;
	Vector3* localPos;
public:
	HealthBar(const char* modelPath, int count, GLuint* texturesID);
	~HealthBar();

	int GetHealth();
	void Decrease();
	void Decrease(int);

	void SetLocalPos(const Vector3& v);

	void Draw();
	void FixedUpdate(int);
};

#endif