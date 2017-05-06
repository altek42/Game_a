#include "Light.h"

std::vector <Light*> Light::lightList;
std::vector <Light*>::iterator Light::id;

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

	return l;
}

void Light::DestroyLights()
{
	for (id = lightList.begin(); id != lightList.end(); id++) {
		lightList.erase(id);
		delete (*id);
	}
}

void Light::SetAmbient(float, float, float, float)
{
}

void Light::SetDifuse(float, float, float, float)
{
}

void Light::SetSpecular(float, float, float, float)
{
}

void Light::SetPosition(Vector3)
{
}

void Light::SetType(char)
{
}

void Light::Draw()
{
}
