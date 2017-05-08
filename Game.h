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

void drawCube(void);
void drawSphere(void);
void drawCone(void);
void drawNone(void);

class Game
{
private:
	int frame;
	GameObject *Root;
public:
	Game();
	~Game();
	void Update();
	void UpdateOnTimer();
private:

};

#endif