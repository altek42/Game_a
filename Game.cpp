#include "Game.h"

Game::Game() {
	this->frame = 0;

	float amb[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	float dif[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	float spe[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	Light::CreateLight(amb, dif, spe);

	GameObject *arena = new GameObject("Data\\Models\\arena.obj", "Data\\Texture\\arena.bmp");
	this->modelsToDelete.push_back(arena->GetModelRef());
	arena->TranslatePosition(Vector3(0, -0.9, 0));

	GameObject *player;
	player = new Player("Data\\Models\\aSw.obj", "Data\\Texture\\aSw.bmp");
	this->modelsToDelete.push_back(player->GetModelRef());
	player->AddAnimation("Run", "Data\\Animations\\RunPlayer", 10, "run");
	player->AddAnimation("Attack", "Data\\Animations\\AttackPlayer", 10, "attack",31);
	player->TranslateRotation(Vector3(0, 180, 0));
	player->GetAllAnimations(&this->animationsToDelete);

	GameObject *enemy1;
	enemy1 = new Enemy("Data\\Models\\enemy1.obj", "Data\\Texture\\enemy1.bmp",player);
	this->modelsToDelete.push_back(enemy1->GetModelRef());
	enemy1->AddAnimation("Jump", "Data\\Animations\\JumpEnemy1", 9, "enemy1_jump", 31);
	enemy1->SetAnimation("Jump");
	enemy1->GetAllAnimations(&this->animationsToDelete);

	GameObject *enemy2;
	enemy2 = new Enemy("Data\\Models\\enemy1.obj", "Data\\Texture\\enemy2.bmp",player);
	this->modelsToDelete.push_back(enemy2->GetModelRef());
	enemy2->AddAnimation("Jump", "Data\\Animations\\JumpEnemy1", 9, "enemy1_jump", 31);
	enemy2->SetAnimation("Jump");
	enemy2->GetAllAnimations(&this->animationsToDelete);
	enemy2->TranslateRotation(Vector3(0, 45, 0));
	enemy2->TranslatePosition(Vector3(3.0f, 0.0f, 3.0f));


	this->Root = new GameObject();
	this->Root->AttachObject(player);
	this->Root->AttachObject(arena);
	this->Root->AttachObject(enemy1);
	this->Root->AttachObject(enemy2);

	Camera::SetPosition(Vector3(3, 3, 3));
	Camera::SetTarget(player);
}

Game::~Game() {
    delete this->Root;
	Light::DestroyLights();
	for (int i = 0; i < modelsToDelete.size(); i++)
	{
		delete modelsToDelete[i];
	}
	for (int i = 0; i < animationsToDelete.size(); i++)
	{
		delete animationsToDelete[i];
	}
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

