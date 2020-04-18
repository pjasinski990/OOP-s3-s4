#pragma once

/*
 * Abstract class for functions manipulation
 */
class Fun 
{
private:

public:
    virtual ~Fun() = default;

    /*
     * Getter for function value.
     *
     * @param x argument for function
     * @return double value of function in argument
     */
    virtual double wartosc(double x) const = 0;

    /*
     * Does same thing as 'wartosc(double x)'
     */
    virtual double operator()(double x) const = 0;

    /*
     * Clones a function.
     *
     * @return Fun* pointer to a resulting copy
     */
    virtual Fun* clone() const = 0;
};