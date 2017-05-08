#include "Game.h"

Game::Game() {
	this->frame = 0;

	float amb[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	float dif[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	float spe[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	Light::CreateLight(amb, dif, spe);

	GameObject *arena = new GameObject("Data\\Models\\arena.obj", "Data\\Texture\\arena.bmp");
	arena->TranslatePosition(Vector3(0, -0.9, 0));

	GameObject *player;
	player = new Player("Data\\Models\\aSw.obj", "Data\\Texture\\aSw.bmp");
	player->AddAnimation("Run", "Data\\Animations\\RunPlayer", 10, "run");
	player->AddAnimation("Attack", "Data\\Animations\\AttackPlayer", 10, "attack",31);
	player->TranslateRotation(Vector3(0, 180, 0));

	GameObject *enemy1;
	enemy1 = new GameObject("Data\\Models\\enemy1.obj", "Data\\Texture\\enemy1.bmp");

	this->Root = new GameObject();
	this->Root->AttachObject(player);
	this->Root->AttachObject(arena);
	this->Root->AttachObject(enemy1);

	Camera::SetPosition(Vector3(3, 3, 3));
	Camera::SetTarget(player);
}

Game::~Game() {
    delete this->Root;
	Light::DestroyLights();
}

void Game::Update() {
	Light::Draw();
	Camera::Draw();
    this->Root->Draw();
}

void Game::UpdateOnTimer()
{
	frame++;
	if (frame > 60) {//per sec
		frame = 0;
	}
	this->Root->FixedUpdate(frame);
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