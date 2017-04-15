#ifndef MODEL_CLASS_H
#define MODEL_CLASS_H

#define _CRT_SECURE_NO_WARNINGS
#include <GL/glut.h>
#include <GL/freeglut.h>
#include <vector>
#include "Vector3.h"

class Model
{
private:
	std::vector <Vector3> vertices;
	std::vector <Vector3> uvs;
	std::vector <Vector3> normals;
	std::vector <unsigned int> vertexIndices;
	std::vector <unsigned int> uvIndices;
	std::vector <unsigned int> normalIndices;

	GLuint textureID;
public:
	Model(const char *);
	~Model();
	void SetTextureID(GLuint);
	void Draw();
};
#endif
