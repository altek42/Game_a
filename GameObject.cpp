#include "GameObject.h"
GameObject* GameObject::Root = NULL;


GameObject::GameObject() : GameObject( NULL , NULL)
{
}

GameObject::GameObject(const char * modelPath) : GameObject(modelPath,NULL)
{
}

GameObject::GameObject(const char *modelPath, const char *texturePath)
{
	if (modelPath == NULL) {
		this->model = NULL;
	}
	else {
		this->model = new Model(modelPath);
		if (texturePath != NULL) {
			this->model->SetTextureID(Texture::CreateTexture(texturePath));
		}
	}
	this->init();
}

GameObject::GameObject(Model * m)
{
	this->model = m;
	this->init();
}

GameObject::GameObject(GameObject* gm)
{
	this->model = gm->model;
	this->objectsList = gm->objectsList;
	for (int i = 0; i < gm->animations.size() ; i++)
	{
		Animation* a = gm->animations[i];
		this->animations.push_back(new Animation(a,this));
	}
	this->actualAnimation = gm->actualAnimation;
	this->init();
}

GameObject::~GameObject()
{
    delete this->position;
    delete this->rotation;
    delete this->scale;
	for (int i = 0; i < this->objectsList.size(); i++)
	{
		delete objectsList[i];
	}
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

void GameObject::SetName(const char * n)
{
	this->name = n;
}

void GameObject::SetAsRoot()
{
	Root = this;
}

Vector3* GameObject::GetPositionRef(){
    return this->position;
}

GLuint GameObject::GetTextureID()
{
	return this->model->GetTextureID();
}

int GameObject::GetAnimationFrame()
{
	return this->animationFrame;
}

Model * GameObject::GetModelRef()
{
	return this->model;
}

void GameObject::GetAllAnimations(std::vector<Animation*>* animList)
{
	for (int i = 0; i < animations.size(); i++)
	{
		animList->push_back(animations[i]);
	}
}

const char * GameObject::GetName()
{
	return this->name;
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

		for (int i = 0; i < this->objectsList.size(); i++)
		{
			objectsList[i]->Draw();
		}

		bool anim = false;
		if (this->actualAnimation != NULL) {
			for (int i = 0; i < animations.size(); i++){
				if (strcmp(actualAnimation, animations[i]->GetName()) == 0) {
					animations[i]->Draw();
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
	for (int i = 0; i < this->objectsList.size(); i++){
		objectsList[i]->FixedUpdate(frame);
	}
	if (this->actualAnimation != NULL) {
		for (int i = 0; i < animations.size(); i++) {
			if (strcmp(actualAnimation, animations[i]->GetName()) == 0) {
				animations[i]->FixedUpdate(frame);
				break;
			}
		}
	}
}

void GameObject::OnCollision(int senderID, GameObject * object)
{
}

int GameObject::GetClassID()
{
	return ID_GAMEOBJECT_CLASS;
}

void GameObject::init()
{
	this->position = new Vector3();
	this->rotation = new Vector3();
	this->scale = new Vector3(1, 1, 1);
	this->actualAnimation = NULL;
	this->name = "[Object]";
	this->ResetAnimationFrame();
}
