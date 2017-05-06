#include "Game.h"

Game::Game() {
	float amb[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	float dif[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	float spe[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	Light::CreateLight(amb, dif, spe);


	this->player = new Player("Models\\a.obj", "Models\\a.bmp");

	this->Root = new GameObject();

    this->ob = new GameObject("Models\\sphere.obj","Models\\sphere2.bmp");
	this->ob->TranslateRotation(Vector3(-25, 0, 0));

	this->obChild = new GameObject("Models\\cube.obj", "Models\\cube.bmp");
    this->obChild->SetPosition(Vector3(2,0,0));
    this->obChild->SetScale(Vector3(1,1,1)*0.5f);
    
	this->obChildChild = new GameObject("Models\\sphere.obj", "Models\\sphere2.bmp");
    this->obChildChild->SetPosition(Vector3(0,1.5f,0));
    this->obChildChild->SetRotation(Vector3(-90,0,0));
	this->obChildChild->SetScale(Vector3(1, 1, 1)*0.5f);


	this->Root->AttachObject(player);
	this->Root->AttachObject(ob);
    this->ob->AttachObject(obChild);
    this->obChild->AttachObject(obChildChild);

	Camera::SetPosition(Vector3(4, 6, 2));
	Camera::SetTarget(player);
}

Game::~Game() {
    delete this->ob;
    delete this->obChild;
    delete this->obChildChild;
    delete this->Root;
	Light::DestroyLights();
}

void Game::Update() {
	Light::Draw();
	Camera::Draw();
	obChild->TranslateRotation(Vector3(0,0.02,0));
	obChildChild->TranslateRotation(Vector3(0.02, 0, 0));
    this->Root->Draw();
}

void drawCube() {
    glColor3f(0.0f, 0.0f, 1.0f);
    glutWireCube(1);
}
void drawSphere() {
    glColor3f(0.0f, 1.0f, 1.0f);
    glutWireSphere(1, 12, 12);
}

void drawCone() {
    glColor3f(1.0f, 1.0f, 0.0f);
    glutWireCone(1.0f, 1.0f, 6, 6);
}

void drawNone(){

}