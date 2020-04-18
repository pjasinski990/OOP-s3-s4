#pragma once
#include "Fun.h"

/*
 * Simple class for calculating derivative of functions.
 * Used with Fun class.
 */
class ProstaRozniczka
{
private:
    double m_step;  // dx value. Determines precision of calculations.
    const Fun* m_fun;
public:
    ProstaRozniczka(double step): m_step{step} {}
    /*
     * Sets function to carry calculations on.
     *
     * @param f function to use in calculations
     * @return ProstaRozniczka* this pointer, used for chaining calls
     */
    ProstaRozniczka* z(const Fun* f) 
    {
        m_fun = f;
        return this;
    }

    /*
     * Calculated derivative of m_fun function in x position.
     *
     * @param x argument of function
     * @return double calculated value of derivative
     */
    double w(double x) const 
    {
        return (m_fun->wartosc(x+m_step) - m_fun->wartosc(x-m_step))/(2*m_step);
    }

    /*
     * Additional operators for commented out part
     */
    const ProstaRozniczka& operator()(const Fun* f)
    {
        m_fun = f;
        return *this;
    }
    double operator()(double x) const 
    {
        return w(x);
    }
};