#include "GameObject.h"


GameObject::GameObject()
{
	this->model = NULL;
	this->texture = NULL;
	this->actualAnimation = NULL;
	this->init();
}

GameObject::GameObject(const char * modelPath)
{
	this->model = new Model(modelPath);
	this->texture = NULL;
	this->actualAnimation = NULL;
	this->init();
}

GameObject::GameObject(const char *modelPath, const char *texturePath)
{
	this->model = new Model(modelPath);
	this->texture = new Texture(texturePath);
	this->model->SetTextureID(this->texture->GetID());
	this->actualAnimation = NULL;
	this->init();
}

GameObject::~GameObject()
{
    delete this->position;
    delete this->rotation;
    delete this->scale;
}

void GameObject::SetPosition(const Vector3& v){
    delete this->position;
    this->position = new Vector3(v);
}
void GameObject::SetRotation(const Vector3& v){
    delete this->rotation;
    this->rotation = new Vector3(v);
}
void GameObject::SetScale(const Vector3& v){
    delete this->scale;
    this->scale = new Vector3(v);
}

void GameObject::SetAnimation(const char * name)
{
	this->actualAnimation = name;
}

Vector3* GameObject::GetPositionRef(){
    return this->position;
}

GLuint GameObject::GetTextureID()
{
	return this->texture->GetID();
}

int GameObject::GetAnimationFrame()
{
	return this->animationFrame;
}

void GameObject::TranslatePosition(const Vector3& v){
    Vector3 vec(this->position);
    vec = vec+v;
    this->SetPosition(vec);
}
void GameObject::TranslateRotation(const Vector3& v){
    Vector3 vec(this->rotation);
    vec = vec+v;
    this->SetRotation(vec);
}
void GameObject::TranslateScale(const Vector3& v){
    Vector3 vec(this->scale);
    vec = vec+v;
    this->SetScale(vec);
}

void GameObject::IncAnimationFrame()
{
	this->animationFrame++;
}

void GameObject::ResetAnimationFrame()
{
	this->animationFrame = 0;
}



void GameObject::AttachObject(GameObject*& o){
    this->objectsList.push_back(o);
}

void GameObject::AddAnimation(const char* animationName, const char* path, int length, const char *fileName)
{
	this->AddAnimation(animationName, path, length, fileName, 61);
}
void GameObject::AddAnimation(const char* animationName, const char* path, int length, const char *fileName,int animatinTime)
{
	Animation* a = new Animation(animationName, path, length, fileName, this);
	a->SetAnimatinTime(animatinTime);
	this->animations.push_back(a);
}


void GameObject::Draw(){
    glPushMatrix();
        glTranslatef(this->position->GetX(),
                     this->position->GetY(),
                     this->position->GetZ()
                    );
        glRotatef(this->rotation->GetX(), 1.0f, 0.0f, 0.0f);
        glRotatef(this->rotation->GetY(), 0.0f, 1.0f, 0.0f);
        glRotatef(this->rotation->GetZ(), 0.0f, 0.0f, 1.0f);
        
        glScalef(this->scale->GetX(),
                 this->scale->GetY(),
                 this->scale->GetZ()
               );

        for(id = this->objectsList.begin(); id != this->objectsList.end(); id++){
            (*id)->Draw();
        }

		bool anim = false;
		if (this->actualAnimation != NULL) {
			for (idAnim = this->animations.begin(); idAnim != this->animations.end(); idAnim++) {
				if (strcmp(actualAnimation, (*idAnim)->GetName()) == 0 ) {
					(*idAnim)->Draw();
					anim = true;
					break;
				}
			}
		}
		
		if (this->model != NULL && anim==false) {
			this->model->Draw();
		}
    glPopMatrix();
}

void GameObject::FixedUpdate(int frame)
{
	for (id = this->objectsList.begin(); id != this->objectsList.end(); id++) {
		(*id)->FixedUpdate(frame);
	}
	if (this->actualAnimation != NULL) {
		for (idAnim = this->animations.begin(); idAnim != this->animations.end(); idAnim++) {
			if (strcmp(actualAnimation, (*idAnim)->GetName()) == 0) {
				(*idAnim)->FixedUpdate(frame);
				break;
			}
		}
	}
}

void GameObject::init()
{
	this->position = new Vector3();
	this->rotation = new Vector3();
	this->scale = new Vector3(1, 1, 1);
}
