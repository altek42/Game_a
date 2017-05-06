#include "Model.h"



Model::Model(const char * path)
{
	textureID = NULL;

	FILE* file = fopen(path, "r");
	if (file == NULL) {
		printf("Impossible to open file!\n");
		exit(-1);
	}
	float x, y, z;
	std::vector <Vector3> _vertices;
	std::vector <Vector3> _uvs;
	std::vector <Vector3> _normals;
	while (1) {
		char lineHeader[128];
		int res = fscanf(file, "%s", lineHeader);
		if (res == EOF) {
			break;
		}

		if (strcmp(lineHeader, "v") == 0) {
			fscanf(file, "%f %f %f\n", &x, &y, &z);
			this->vertices.push_back(Vector3(x, y, z));
		}
		else if (strcmp(lineHeader, "vt") == 0) {
			fscanf(file, "%f %f\n", &x, &y);
			this->uvs.push_back(Vector3(x, y, 0));
		}
		else if (strcmp(lineHeader, "vn") == 0) {
			fscanf(file, "%f %f %f\n", &x, &y, &z);
			this->normals.push_back(Vector3(x, y, z));
		}
		else if (strcmp(lineHeader, "f") == 0) {
			unsigned int verIndex[3], uvIndex[3], norIndex[3];
			int matches = fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n",
				&verIndex[0], &uvIndex[0], &norIndex[0],
				&verIndex[1], &uvIndex[1], &norIndex[1],
				&verIndex[2], &uvIndex[2], &norIndex[2]
				);
			if (matches != 9) {
				printf("File can't be read by our simple parser : ( Try exporting with other options\n");
				exit(-1);
			}
			this->vertexIndices.push_back(verIndex[0]);
			this->vertexIndices.push_back(verIndex[1]);
			this->vertexIndices.push_back(verIndex[2]);
			this->uvIndices.push_back(uvIndex[0]);
			this->uvIndices.push_back(uvIndex[1]);
			this->uvIndices.push_back(uvIndex[2]);
			this->normalIndices.push_back(norIndex[0]);
			this->normalIndices.push_back(norIndex[1]);
			this->normalIndices.push_back(norIndex[2]);
		}
	}
	fclose(file);
}


Model::~Model()
{
}

void Model::SetTextureID(GLuint id)
{
	this->textureID = id;
}

void Model::Draw()
{
	glPushMatrix();
	
	float m0_amb[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	float m0_dif[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	float m0_spe[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	glMaterialfv(GL_FRONT, GL_AMBIENT, m0_amb);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, m0_dif);
	glMaterialfv(GL_FRONT, GL_SPECULAR, m0_spe);
	glMaterialf(GL_FRONT, GL_SHININESS, 20.0f);

	//glColor3f(0.5, 0.5, 0.5);
	glFrontFace(GL_CW);
	//glPolygonMode(GL_FRONT, GL_FILL);
	//glPolygonMode(GL_BACK, GL_LINE);
	if (textureID != NULL) {
		glBindTexture(GL_TEXTURE_2D, textureID);
	}

	glBegin(GL_TRIANGLES);
	
	for (unsigned int i = 0; i < vertexIndices.size(); i++) {
		unsigned int vIndex = vertexIndices[i];
		unsigned int nIndex = normalIndices[i];
		Vector3 vec;
		if (textureID != NULL) {
			unsigned int uIndex = uvIndices[i];
			vec = uvs[uIndex - 1];
			glTexCoord2f(vec.GetX(), vec.GetY());
		}
 		vec = normals[nIndex -1];
		glNormal3f(vec.GetX(), vec.GetY(), vec.GetZ());
		vec = vertices[vIndex-1];
		glVertex3f(vec.GetX(), vec.GetY(), vec.GetZ());
	}
	glEnd();

	glPopMatrix();
}
