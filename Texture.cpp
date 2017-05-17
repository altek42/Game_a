#include "Texture.h"


Texture::Texture()
{
	
}

Texture::~Texture()
{
}

GLuint Texture::CreateTexture(const char * imagepath)
{
	GLuint textureID;
	FILE * file = fopen(imagepath, "rb");
	if (!file) {
		printf("Image could not be opened\n");
		exit(-2);
	}

	// Data read from the header of the BMP file
	unsigned char header[54]; // Each BMP file begins by a 54-bytes header
	unsigned int dataPos;     // Position in the file where the actual data begins
	unsigned int width, height;
	unsigned int imageSize;   // = width*height*3
	unsigned char * data;	// Actual RGB data

	if (fread(header, 1, 54, file) != 54) { // If not 54 bytes read : problem
		printf("Not a correct BMP file\n");
		exit(-2);
	}
	if (header[0] != 'B' || header[1] != 'M') {
		printf("Not a correct BMP file\n");
		exit(-2);
	}
	// Read ints from the byte array
	dataPos = *(int*)&(header[0x0A]);
	imageSize = *(int*)&(header[0x22]);
	width = *(int*)&(header[0x12]);
	height = *(int*)&(header[0x16]);
	if (imageSize == 0)    imageSize = width*height * 3; // 3 : one byte for each Red, Green and Blue component
	if (dataPos == 0)      dataPos = 54; // The BMP header is done that way
	data = new unsigned char[imageSize];
	fread(data, 1, imageSize, file);
	fclose(file);

	glGenTextures(1, &textureID);
	// "Bind" the newly created texture : all future texture functions will modify this texture
	glBindTexture(GL_TEXTURE_2D, textureID);
	// Give the image to OpenGL
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, data);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	return textureID;
}
