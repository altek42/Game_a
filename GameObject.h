#ifndef GAME_OBJECT_CLASS_H
#define GAME_OBJECT_CLASS_H
#include <GL/glut.h>
#include <GL/freeglut.h>
#include <vector>
#include "Vector3.h"
#include "Texture.h"
#include "Model.h"
#include "Animation.h"
#include "Collider.h"

#define ID_GAMEOBJECT_CLASS 1
#define ID_ENEMY_CLASS 2
#define ID_PLAYER_CLASS 3

class Animation;
class GameObject
{
protected:
	static GameObject* Root;

	const char* name;

    std::vector <GameObject*> objectsList;
	std::vector <Animation*> animations;

    Vector3* position;
    Vector3* rotation;
    Vector3* scale;

	Model* model;
	
	int animationFrame;
	const char* actualAnimation;
public:
	GameObject();
	GameObject(const char*);
	GameObject(const char*, const char*);
	GameObject(Model*);
	GameObject(GameObject*);
	virtual ~GameObject();

    void SetPosition(const Vector3&);
    void SetRotation(const Vector3&);
    void SetScale(const Vector3&);
	void SetAnimation(const char*);
	void SetName(const char*);
	void SetAsRoot();

    Vector3* GetPositionRef();
	GLuint GetTextureID();
	int GetAnimationFrame();
	Model* GetModelRef();
	void GetAllAnimations(std::vector<Animation*> * animList);
	const char* GetName();

    void TranslatePosition(const Vector3&);
    void TranslateRotation(const Vector3&);
    void TranslateScale(const Vector3&);

	void IncAnimationFrame();
	void ResetAnimationFrame();

	void AttachObject(GameObject*&);
	void AddAnimation(const char* animationName, const char* path, int length, const char *fileName);
	void AddAnimation(const char* animationName, const char* path, int length, const char *fileName,int animationTime);
    virtual void Draw();
	virtual void FixedUpdate(int);
	virtual void OnCollision(int senderID, GameObject* object);

	virtual int GetClassID();
private:

	void init();
};

#endif