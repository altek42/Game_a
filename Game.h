#ifndef GAME_CLASS_H
#define GAME_CLASS_H
#include <stdio.h>
#include "GameObject.h"
#include "Mouse.h"
#include "Camera.h"
#include "Player.h"
#include "Model.h"
#include "Texture.h"
#include "Light.h"
#include "Enemy.h"
#include "HealthBar.h"

class Game
{
private:
	static bool gameOver;

	std::vector <Model*> modelsToDelete;
	std::vector <Animation*> animationsToDelete;

	int frame;
	GameObject *Root;
public:
	Game();
	~Game();
	void Update();
	void UpdateOnTimer();

	static void GameOver();
private:

};

#endif