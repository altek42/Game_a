#ifndef KEYBOARD_CLASS_H
#define KEYBOARD_CLASS_H
#include <iostream>
#define KEY_ESC 27
#define KEY_SPACE 32

class Keyboard
{
	static int delay;
	static int delayUp;
	static bool keyState[256];
	static unsigned char key;
	static unsigned char keyUp;
public:
	static void Update();
	static void FixedUpdate();
	static void OnKeyPress(unsigned char, int, int);
	static void OnKeyUp(unsigned char, int, int);
	static bool isPressed(unsigned char);
	static char GetKey();
	static char GetKeyUp();
private:
	Keyboard();
	~Keyboard();

};
#endif