#include "Keyboard.h"

int Keyboard::delay = 0;;
int Keyboard::delayUp = 0;;
bool Keyboard::keyState[256];
unsigned char Keyboard::key = 0;
unsigned char Keyboard::keyUp = 0;

Keyboard::Keyboard() {
}

Keyboard::~Keyboard() {
}

void Keyboard::Update()
{
	
}

void Keyboard::FixedUpdate(){
	if (delay <= 0) {
		key = 0;
	}
	else if (delay > 0) {
		delay--;
	}
	if (delayUp <= 0) {
		keyUp = 0;
	}
	else if (delayUp > 0) {
		delay--;
	}
}

void Keyboard::OnKeyPress(unsigned char _key, int x, int y) {
	if (!keyState[_key]) {
		key=_key;
		delay = 10;
	}
	keyState[key] = true;
}

void Keyboard::OnKeyUp(unsigned char _key, int x, int y)
{
	if (keyState[_key]) {
		keyUp = _key;
		delayUp = 100000;
	}
	keyState[_key] = false;
}

bool Keyboard::isPressed(unsigned char key)
{
	return keyState[key];
}

char Keyboard::GetKey(){
    return key;
}

char Keyboard::GetKeyUp()
{
	return keyUp;
}
