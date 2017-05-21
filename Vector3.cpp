#include "Vector3.h"

Vector3::Vector3(float v)
{
	this->x = v;
	this->y = v;
	this->z = v;
}

Vector3::Vector3(float x,float y,float z) {
    this->x=x;
    this->y=y;
    this->z=z;
}

Vector3::Vector3(const Vector3& vec) {
    this->x=vec.x;
    this->y=vec.y;
    this->z=vec.z;
}
Vector3::Vector3(Vector3*& vec) {
    this->x=vec->x;
    this->y=vec->y;
    this->z=vec->z;
}

Vector3::Vector3() {
    this->x=0;
    this->y=0;
    this->z=0;
}

Vector3::~Vector3() {
}

float Vector3::GetX() {
    return this->x;
}
float Vector3::GetY() {
    return this->y;
}
float Vector3::GetZ() {
    return this->z;
}
float Vector3::GetLenght() {
    return sqrt(pow(this->x,2)+pow(this->y,2)+pow(this->z,2));
}

void Vector3::SetX(float x) {
    this->x=x;
}
void Vector3::SetY(float y) {
    this->y=y;
}
void Vector3::SetZ(float z) {
    this->z=z;
}
void Vector3::Set(const Vector3& vec) {
    this->x=vec.x;
    this->y=vec.y;
    this->z=vec.z;
}
void Vector3::Set(float x,float y,float z) {
    this->x=x;
    this->y=y;
    this->z=z;
}

Vector3 Vector3::operator= (const Vector3& v) {
	return Vector3(this->x = v.x,
				   this->y = v.y,
				   this->z = v.z);
}

Vector3 Vector3::operator+ (Vector3*& v) {
    return Vector3 (this->GetX() + v->x,
                    this->GetY() + v->y,
                    this->GetZ() + v->z
                   );
}
Vector3 Vector3::operator+ (const Vector3& v) {
    return Vector3 (this->GetX() + v.x,
                    this->GetY() + v.y,
                    this->GetZ() + v.z
                   );
}
Vector3 Vector3::operator+ (float c) {
    return Vector3 (this->GetX() + c,
                    this->GetY() + c,
                    this->GetZ() + c
                   );
}
Vector3 Vector3::operator- (Vector3*& v) {
    return Vector3 (this->GetX() - v->x,
                    this->GetY() - v->y,
                    this->GetZ() - v->z
                   );
}
Vector3 Vector3::operator- (const Vector3& v) {
    return Vector3 (this->GetX() - v.x,
                    this->GetY() - v.y,
                    this->GetZ() - v.z
                   );
}
Vector3 Vector3::operator- (float c) {
    return Vector3 (this->GetX() - c,
                    this->GetY() - c,
                    this->GetZ() - c
                   );
}
Vector3 Vector3::operator* (float c) {
    return Vector3 (this->GetX() * c,
                    this->GetY() * c,
                    this->GetZ() * c
                   );
}
Vector3 Vector3::operator/ (float c) {
    return Vector3 (this->GetX() / c,
                    this->GetY() / c,
                    this->GetZ() / c
                   );
}

Vector3 Vector3::DirectionTo(Vector3 * target)
{
	float x = (this->GetX() - target->GetX());
	float y = (this->GetY() - target->GetY());
	float z = (this->GetZ() - target->GetZ());

	//float f[] = { fabs(x),fabs(y),fabs(z) };
	//float max = *std::max_element(f, f + 7);
	float len = Vector3(x, y, z).GetLenght();
	float sum = fabs(x) + fabs(y) + fabs(z);
	if (sum != 0) {
		//x = x < 0 ? fabs(x) / sum
		x = x / sum;
		y = y / sum;
		z = z / sum;
	}
	else {
		x = y = z = 0;
	}
	return Vector3(x,y,z);
}

std::ostream& operator<<(std::ostream& out, const Vector3& v)  
{  
    return out << "X: "<< v.x<<" Y: "<< v.y<<" Z: "<< v.z ;
} 