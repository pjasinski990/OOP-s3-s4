#include "Vector2D.h"

int Vector2D::count = 0;

Vector2D::Vector2D(double x, double y): _x(x), _y(y) {
	count++;
}

Vector2D::Vector2D(const Vector2D& v): _x(v._x), _y(v._y) {
	print("copying ");
	count++;
}

Vector2D::Vector2D(const Vector2D&& v): _x(v._x), _y(v._y){
	print("moving ");
	count++;
}

Vector2D::~Vector2D() {
	count--;
}

Vector2D Vector2D::fromCarthesian(double x, double y) {
	return Vector2D(x, y);
}

Vector2D Vector2D::fromPolar(double r, double phi) {
	return Vector2D(r*cos(phi*2*M_PI/360), r*sin(phi*2*M_PI/360));
}

void Vector2D::print(std::string msg) const {
	std::cout << msg << "(" << _x << ", " << _y << ")" << std::endl;
}

double Vector2D::dot(const Vector2D& v) const {
	return _x*v._x + _y*v._y;
}

Vector2D Vector2D::add(const Vector2D& v) const {
	Vector2D temp = Vector2D(_x, _y);
	temp._x += v._x;
	temp._y += v._y;
	return temp;
}
