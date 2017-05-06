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

void drawCube(void);
void drawSphere(void);
void drawCone(void);
void drawNone(void);

class Game
{
private:
	GameObject *player;
	GameObject *Root;
	GameObject *ob, *obChild, *obChildChild;
	//GameObject *arena;
public:
	Game();
	~Game();
	void Update();

private:

};

#endif