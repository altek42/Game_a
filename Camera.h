#ifndef CAMERA_CLASS_H
#define CAMERA_CLASS_H
#include "GameObject.h"
#include "Vector3.h"
class Camera{
	static Vector3* Position;
    static GameObject* Target;
    static Vector3* Up;
public:
	static void Delete();

	static void SetPosition(const Vector3&);
	static void SetTarget(GameObject*);
	static void SetUp(const Vector3&);

	static Vector3 GetPosition();

	static void TranslatePosition(const Vector3&);

    static void Draw();
private:
    Camera();
    ~Camera();
};

#endif