#include "Keyboard.h"

int Keyboard::delay = 0;;
bool Keyboard::keyState[256];
unsigned char Keyboard::key = 0;

Keyboard::Keyboard() {
}

Keyboard::~Keyboard() {
}

void Keyboard::Update()
{
	if (delay <= 0) {
		key = 0;
	}
	else if (delay > 0) {
		delay--;
	}
}

void Keyboard::OnKeyPress(unsigned char _key, int x, int y) {
	if (!keyState[_key]) {
		key=_key;
		delay = 100;
	}
	keyState[key] = true;
    //std::cout << "key: "<<key<<"   x: "<<x<<"   y: "<<y << std::endl;
}

void Keyboard::OnKeyUp(unsigned char key, int x, int y)
{
	keyState[key] = false;
}

bool Keyboard::isPressed(unsigned char key)
{
	return keyState[key];
}

char Keyboard::GetKey(){
    return key;
}