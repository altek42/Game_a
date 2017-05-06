#ifndef Light_CLASS_H
#define Light_CLASS_H
#include <GL/glut.h>
#include <GL/freeglut.h>
#include <vector>
#include "Vector3.h"

class Light
{
	static std::vector <Light*> lightList;
	static std::vector <Light*>::iterator id;

	float amb[4];
	float dif[4];
	float spe[4];
	Vector3 Position;
	char type;
	
public:
	static Light* CreateLight(float*, float*, float*);
	static void DestroyLights();

	void SetAmbient(float, float, float, float);
	void SetDifuse(float, float, float, float);
	void SetSpecular(float, float, float, float);
	void SetPosition(Vector3);
	void SetType(char);

	static void Draw();
private:
	Light(float*, float*, float*, float*);
	~Light();
};

#endif