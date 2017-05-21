#include "HealthBar.h"



HealthBar::HealthBar(const char* modelPath, int count, GLuint* texturesID)
	: GameObject(modelPath)
{
	this->localPos = new Vector3();;
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
	delete this->localPos;
}

int HealthBar::GetHealth()
{
	return this->actualHealth;
}

void HealthBar::Decrease()
{
	this->Decrease(1);
}

void HealthBar::Decrease(int count)
{
	this->actualHealth -= count;
	if (this->actualHealth < 0) {
		this->actualHealth = 0;
	}
}

void HealthBar::SetLocalPos(const Vector3& v)
{
	delete this->localPos;
	this->localPos = new Vector3(v);
}



void HealthBar::Draw()
{
	this->SetPosition(Camera::GetPosition());
	this->TranslatePosition(Vector3(-0.2, -0.2, -0.2));
	this->TranslatePosition(this->localPos);

	if (this->actualHealth == 0) {
		this->model->SetTextureID(NULL);
	}
	else {
		this->model->SetTextureID(this->textures[this->actualHealth - 1]);
	}
	GameObject::Draw();
}

void HealthBar::FixedUpdate(int frame)
{
	
}

