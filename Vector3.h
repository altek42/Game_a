#ifndef VECTOR3_CLASS_H
#define VECTOR3_CLASS_H
#include <iostream>
#include <math.h>
#include <algorithm>
class Vector3
{
    float x,y,z;
public:
	Vector3(float);
	Vector3(float,float,float);
    Vector3(const Vector3&);
    Vector3(Vector3*&);
    Vector3();
    ~Vector3();

    float GetX();
    float GetY();
    float GetZ();
    float GetLenght();

    void SetX(float);
    void SetY(float);
    void SetZ(float);
    void Set(const Vector3&);
    void Set(float,float,float);

    Vector3 operator= (const Vector3&);
    Vector3 operator+ (Vector3*&);
    Vector3 operator+ (const Vector3&);
    Vector3 operator+ (float);
    Vector3 operator- (Vector3*&);
    Vector3 operator- (const Vector3&);
    Vector3 operator- (float);  
    Vector3 operator* (float);    
    Vector3 operator/ (float);  
    friend std::ostream& operator<< (std::ostream&,const Vector3&);  

	Vector3 DirectionTo(Vector3* target);
private:
    
};


#endif