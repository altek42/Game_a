#ifndef TEXTURE_CLASS_H
#define TEXTURE_CLASS_H

#define _CRT_SECURE_NO_WARNINGS

#include <GL/glut.h>
#include <GL/freeglut.h>
#include <stdio.h>

class Texture
{
	GLuint textureID;

public:
	Texture(const char *);
	GLuint GetID();
	~Texture();
};

#endif
