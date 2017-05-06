#include "Light.h"

std::vector <Light*> Light::lightList;
std::vector <Light*>::iterator Light::id;
int Light::count=0;


Light::Light(float* amb, float* dif, float* spe, float* pos)
{
	this->amb[0] = amb[0];
	this->amb[1] = amb[1];
	this->amb[2] = amb[2];
	this->amb[3] = amb[3];

	this->dif[0] = dif[0];
	this->dif[1] = dif[1];
	this->dif[2] = dif[2];
	this->dif[3] = dif[3];

	this->spe[0] = spe[0];
	this->spe[1] = spe[1];
	this->spe[2] = spe[2];
	this->spe[3] = spe[3];

	this->Position = Vector3(pos[0], pos[1], pos[2]);
	this->type = (char)pos[3];
}


Light::~Light()
{

}

Light * Light::CreateLight(float *amb, float *dif, float *spe)
{
	float p[]= { 0.0f, 0.0f, 0.0f, 1.0f };
	Light *l = new Light(amb, dif, spe, p);
	lightList.push_back(l);

	glEnable(GL_LIGHT0 + count);
	count++;
	return l;
}

void Light::DestroyLights()
{
	for (id = lightList.begin(); id != lightList.end(); id++) {
		lightList.erase(id);
		delete (*id);
	}
}

void Light::SetAmbient(float r, float g, float b, float a)
{
	this->amb[0] = r;
	this->amb[1] = g;
	this->amb[2] = b;
	this->amb[3] = a;
}

void Light::SetDifuse(float r, float g, float b, float a)
{
	this->dif[0] = r;
	this->dif[1] = g;
	this->dif[2] = b;
	this->dif[3] = a;
}

void Light::SetSpecular(float r, float g, float b, float a)
{
	this->spe[0] = r;
	this->spe[1] = g;
	this->spe[2] = b;
	this->spe[3] = a;
}

void Light::SetPosition(Vector3 position)
{
	this->Position = position;
}

void Light::SetType(char type)
{
	this->type = type;
}

void Light::Draw()
{
	int i=0;
	for (id = lightList.begin(); id != lightList.end(); id++, i++) {
		glLightfv(GL_LIGHT0 + i, GL_AMBIENT, (*id)->amb );
		glLightfv(GL_LIGHT0 + i, GL_DIFFUSE, (*id)->dif);
		glLightfv(GL_LIGHT0 + i, GL_SPECULAR, (*id)->spe);
		float p[] = { (*id)->Position.GetX(), (*id)->Position.GetY(), (*id)->Position.GetZ(), (float) (*id)->type };
		glLightfv(GL_LIGHT0 + i, GL_POSITION, p);
	}
}
