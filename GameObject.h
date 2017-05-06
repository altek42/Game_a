#ifndef GAME_OBJECT_CLASS_H
#define GAME_OBJECT_CLASS_H
#include <GL/glut.h>
#include <GL/freeglut.h>
#include <vector>
#include "Vector3.h"
#include "Texture.h"
#include "Model.h"
#include "Animation.h"

class GameObject
{
protected:
    std::vector <GameObject*> objectsList;
    std::vector <GameObject*>::iterator id;

	std::vector <Animation*> animations;
	std::vector <Animation*>::iterator idAnim;

    Vector3* position;
    Vector3* rotation;
    Vector3* scale;

	Model* model;
	Texture* texture;
	
	int frame;
	const char* actualAnimation;
public:
	GameObject();
	GameObject(const char*);
	GameObject(const char*, const char*);
	virtual ~GameObject();

    void SetPosition(const Vector3&);
    void SetRotation(const Vector3&);
    void SetScale(const Vector3&);
	void SetAnimation(const char*);

    Vector3* GetPositionRef();

    void TranslatePosition(const Vector3&);
    void TranslateRotation(const Vector3&);
    void TranslateScale(const Vector3&);

	void AttachObject(GameObject*&);
	void AddAnimation(const char* animationName, const char* path, int length, const char *fileName);
    virtual void Draw();
	virtual void FixedUpdate(int);
private:
	void init();
};

#endif