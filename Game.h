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
#include "UIElement.h"
#include "UICounter.h"
#include "Arena.h"

class Enemy;
class Game
{
private:
	static Game* _instance;
	static bool gameOver;

	bool isStart;
	bool isInstruction;

	std::vector <Model*> modelsToDelete;
	std::vector <Animation*> animationsToDelete;

	int frame;
	GameObject *Root;
	UIElement* TextGameOver;
	UIElement* Menu;
	
	Game();
public:
	static Game* GetInstance();
	~Game();
	void Update();
	void UpdateOnTimer();
	GameObject* GetRootObject();

	static void GameOver();
private:

};

#endif