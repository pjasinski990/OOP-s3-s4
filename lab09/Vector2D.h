#pragma once
#include <iostream>
#include <cmath>
#include <utility>

/*
 * Simple class for creating and operating on two dimensional vectors.
 */
class Vector2D {
public:
	/* Count of currently existing vectors */
	static int count;

	/*
	 * Copy constructor
	 */
	Vector2D(const Vector2D& v);
	/*
	 * Move constructor
	 */
	Vector2D(const Vector2D&& v);
	/*
	 * Destructor. Decreases number of existing vectors.
	 */
	~Vector2D();
	
	/*
	 * Static method for creating vectors using carthesian coordinates.
	 * \param x first coordinate
	 * \param y second coordinate
	 * \return created vector
	 */
	static Vector2D fromCarthesian(double x, double y);
	/*
	 * Static method for creating vectors using polar coordinates.
	 * \param r polar radius
	 * \param phi polar angle
	 * \return created vector
	 */
	static Vector2D fromPolar(double r, double phi);
	/*
	 * Fancy way of printing your vector.
	 * \param msg message to print before actual coordinates.
	 * \return void
	 */
	void print(std::string msg) const;
	/*
	 * Calculates dot product of object and parameter vectors.
	 * \param v second vector operand
	 * \return double value of dot product 
	 */
	double dot(const Vector2D& v) const;
	/*
	 * Returns vector being the sum of your object and passed vector. 
	 * \param v second vector operand
	 * \return Vector2D result vector
	 */
	Vector2D add(const Vector2D& v) const;

private:
	/*
	 * Constructor for vector class.
	 * Supposed to be called only by fromCarthesian and fromPolar static methods.
	 * That ensures creating vector using correct coordinates system.
	 */
	Vector2D(double x, double y);
	/*
	 * x coordinate of vector
	 */
	double _x;
	/*
	 * y coordinate of vector
	 */
	double _y;
};
