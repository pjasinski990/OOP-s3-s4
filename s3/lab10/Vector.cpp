#include "Vector.h"

Vector::Vector(int dim): _dim(dim), _data(new double[dim]) {
	for (int i = 0; i < dim; i++) {
		_data[i] = 0;
	}
}
Vector::Vector(const Vector& o): _dim(o._dim), _data(new double[_dim]) {
	for (int i = 0; i < _dim; i++) {
		_data[i] = o._data[i];
	}
}
Vector::Vector(Vector&& o): _dim(o._dim), _data(o._data) {
	o._data = nullptr;
}
Vector::~Vector() {delete[] _data;}


double Vector::dot(const Vector& v1, const Vector& v2) {
	double product = 0;
	if (v1._dim != v2._dim) {
		std::cout << "Vectors dimensions not matching." << std::endl;
		return v1;
	}

	for (int i = 0; i < v1._dim; i++) {
		product += v1._data[i]*v2._data[i];
	}
	return product;
}
Vector Vector::sum(const Vector& v1, const Vector& v2) {
	if (v1._dim != v2._dim) {
		std::cout << "Vectors dimensions not matching." << std::endl;
		return v1;
	}
	Vector temp(v1);
	for (int i = 0; i < temp._dim; i++) {
		temp._data[i] += v2._data[i];
	}
	return temp;
}
Vector Vector::sum(const Vector& v, int increment) {
	Vector temp(v);
	for (int i = 0; i < v._dim; i++) {
		temp._data[i] += increment;
	}
	return temp;
}

Vector::operator double() const {
	return norm();
}

double& Vector::at(int index) {
	return _data[index];
}
double Vector::norm() const {
	double temp = 0;
	for (int i = 0; i < _dim; i++) {
		temp += pow(_data[i], 2);
	}
	return sqrt(temp);
}
void Vector::print(std::string msg) const {
	std::cout << msg << "(";
	for (int i = 0; i < _dim-1; i++) {
		std::cout << _data[i] << ", ";
	}
	std::cout << _data[_dim-1] << ")" << std::endl;
}
