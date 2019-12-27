#pragma once
#include <cstring>
#include <iostream>
#include <cmath>

/*
 * Class for creating and basic manipulation on n-dimensional vectors.
 */
class Vector {
public:
	/*
	 * Constructor with dimension argument
	 */
	explicit Vector(int dim);
	/*
	 * Copy constructor
	 */
	Vector(const Vector& o);
	/* Moving constructor
	 */
	Vector(Vector&& o);
	/*
	 * Destructor
	 */
	~Vector();

	/*
	 * Calculates dot product of two vectors passed as arguments.
	 * \param v1 first vector
	 * \param v2 second vector
	 * \return double dot product
	 */
	static double dot(const Vector& v1, const Vector& v2);
	/*
	 * Creates vector being sum of passed vector parameters.
	 * \param v1 first vector
	 * \param v2 second vector
	 * \return Vector created sum vector
	 */
	static Vector sum(const Vector& v1, const Vector& v2);

	/*
	 * Creates vector with all dimensions incremented by int value.
	 * \param v Vector to add to
	 * \param increment increment value
	 */
	static Vector sum(const Vector& v, int increment);

	/*
	 * Double conversion operator
	 */
	operator double() const;

	/*
	 * Method used to access and modify vector coordinates.
	 * \param index index of dimension value to be returned
	 * \return double& reference to dimension value
	 */
	double& at(int index);
	/*
	 * Calculates norm of vector.
	 * \return double calculated norm
	 */
	double norm() const;
	/*
	 * Prints vector in a fancy way.
	 * \param msg message to preceed vector data
	 * \return void
	 */
	void print(std::string msg) const;
private:
	// _dim number of dimensions of vector
	int _dim;
	// _data array of dimension coordinates values
	double* _data;
};
