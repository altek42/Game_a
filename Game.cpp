#include "Game.h"

bool Game::gameOver=false;


Game::Game() {
	this->frame = 0;

	float amb[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	float dif[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	float spe[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	Light::CreateLight(amb, dif, spe);

	GameObject *arena = new GameObject("Data\\Models\\arena.obj", "Data\\Texture\\arena.bmp");
	this->modelsToDelete.push_back(arena->GetModelRef());
	arena->TranslatePosition(Vector3(0, -0.9, 0));

	HealthBar *playerBar;
	GLuint tex[4];
	tex[0] = Texture::CreateTexture("Data\\Texture\\healthBar1.bmp");
	tex[1] = Texture::CreateTexture("Data\\Texture\\healthBar2.bmp");
	tex[2] = Texture::CreateTexture("Data\\Texture\\healthBar3.bmp");
	tex[3] = Texture::CreateTexture("Data\\Texture\\healthBar4.bmp");
	playerBar = new HealthBar("Data\\Models\\healthBar.obj", 4, tex);
	this->modelsToDelete.push_back(playerBar->GetModelRef());
	playerBar->SetScale(Vector3(0.03f));
	playerBar->SetRotation(Vector3(0, 45, 0));
	playerBar->SetLocalPos(Vector3(0, 0.08f, 0));
	GameObject *playerBarGO = playerBar;

	GameObject *player;
	player = new Player("Data\\Models\\aSw.obj", "Data\\Texture\\aSw.bmp", playerBar);
	this->modelsToDelete.push_back(player->GetModelRef());
	player->AddAnimation("Run", "Data\\Animations\\RunPlayer", 10, "run");
	player->AddAnimation("Attack", "Data\\Animations\\AttackPlayer", 10, "attack", 31);
	player->TranslateRotation(Vector3(0, 180, 0));
	player->GetAllAnimations(&this->animationsToDelete);
	player->SetName("Player");

	GameObject *enemy1;
	enemy1 = new Enemy("Data\\Models\\enemy1.obj", "Data\\Texture\\enemy1.bmp",player);
	this->modelsToDelete.push_back(enemy1->GetModelRef());
	enemy1->AddAnimation("Jump", "Data\\Animations\\JumpEnemy1", 9, "enemy1_jump", 31);
	enemy1->SetAnimation("Jump");
	enemy1->GetAllAnimations(&this->animationsToDelete);
	enemy1->TranslatePosition(Vector3(3.0f, 0.0f, 0.0f));
	enemy1->SetName("Zielony{1}");

	GameObject *enemy2;
	enemy2 = new Enemy("Data\\Models\\enemy1.obj", "Data\\Texture\\enemy2.bmp",player);
	this->modelsToDelete.push_back(enemy2->GetModelRef());
	enemy2->AddAnimation("Jump", "Data\\Animations\\JumpEnemy1", 9, "enemy1_jump", 31);
	enemy2->SetAnimation("Jump");
	enemy2->GetAllAnimations(&this->animationsToDelete);
	enemy2->TranslateRotation(Vector3(0, 45, 0));
	enemy2->TranslatePosition(Vector3(3.0f, 0.0f, 3.0f));
	enemy2->SetName("Niebieski{2}");


	this->Root = new GameObject();
	this->Root->AttachObject(playerBarGO);
	this->Root->AttachObject(player);
	this->Root->AttachObject(arena);
	this->Root->AttachObject(enemy1);
	this->Root->AttachObject(enemy2);

	Camera::SetPosition(Vector3(3));
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
	if (gameOver) {

	}
	else {
		Light::Draw();
		Camera::Draw();
		this->Root->Draw();
	}
}

void Game::UpdateOnTimer()
{
	if (gameOver) {

	}
	else {
		frame++;
		if (frame > 60) {//per sec
			frame = 0;
		}
		this->Root->FixedUpdate(frame);
		Collider::CheckCollisions();
	}
}

void Game::GameOver()
{
	gameOver = true;
}

