#include "UICounter.h"



UICounter::UICounter(const char* mp, const char* tp, const char* tname, int count) : UIElement (mp)
{
	this->pointer = 0;
	this->count = count;
	this->numbers = new GLuint[count]();

	for (int i = 0; i < count; i++)
	{
		char p[500];
		strcpy(p, tp);
		strcat(p, "\\");
		strcat(p, tname);
		if (count > 100) {
			//errr
		}

		if (i < 10) {
			strcat(p, "0");
			char liczba[3];
			_itoa(i, liczba, 10);
			strcat(p, liczba);
		}
		else if (i < 100) {
			char liczba[3];
			_itoa(i, liczba, 10);
			strcat(p, liczba);
		}
		strcat(p, ".bmp");
		
		numbers[i] = Texture::CreateTexture(p);
	}
	this->model->SetTextureID(this->numbers[pointer]);
}


UICounter::~UICounter()
{
	delete[] this->numbers;
}

void UICounter::Draw()
{
	
	UIElement::Draw();
}

void UICounter::FixedUpdate(int frame)
{
	
	UIElement::FixedUpdate(frame);
}
