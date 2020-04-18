#pragma once
#include <cmath>
#include "Fun.h"

class Liniowa: public Fun
{
public:
    Liniowa(): m_a{0}, m_b{0} {}
    Liniowa(const Liniowa& o): m_a{o.m_a}, m_b{o.m_b} {}
    
    /*
     * Static factory. Creates new instance of Liniowa class.
     *
     * @return Fun* created instance
     */
    static Liniowa* utworz() {return new Liniowa();}

    /*
     * See Fun::clone()
     */
    Fun* clone() const override
    {
        return new Liniowa(*this);
    }
    
    Liniowa* a(double val) 
    {
        m_a = val;
        return this;
    }

    Liniowa* b(double val) 
    {
        m_b = val;
        return this;
    }

    double wartosc(double x) const override {return m_a*x + m_b;}

    double operator()(double x) const override {return wartosc(x);}

private:
    double m_a;
    double m_b;
};

class Kwadratowa: public Fun
{
public:
    Kwadratowa(): m_a{0}, m_b{0}, m_c{0} {}
    Kwadratowa(const Kwadratowa& o): m_a{o.m_a}, m_b{o.m_b}, m_c{o.m_c} {}

    /*
     * Static factory. Creates new instance of Kwadratowa class.
     *
     * @return Fun* created instance
     */
    static Kwadratowa* utworz() {return new Kwadratowa();}

    /*
     * See Fun::clone()
     */
    Fun* clone() const override
    {
        return new Kwadratowa(*this);
    }
    
    Kwadratowa* a(double val)
    {
        m_a = val;
        return this;
    }
    
    Kwadratowa* b(double val)
    {
        m_b = val;
        return this;
    }

    Kwadratowa* c(double val)
    {
        m_c = val;
        return this;
    }
    double wartosc(double x) const override {return m_a*x*x + m_b*x + m_c;}

    double operator()(double x) const override {return wartosc(x);}

private:
    double m_a;
    double m_b;
    double m_c;
};

class Sinus: public Fun
{    
public:
    Sinus() {}
    Sinus(const Sinus& o) {}

    /*
     * Static factory. Creates new instance of Sinus class.
     *
     * @return Fun* created instance
     */
    static Sinus* utworz() {return new Sinus();}

    /*
     * See Fun::clone()
     */
    Fun* clone() const override
    {
        return new Sinus(*this);
    }

    double wartosc(double x) const override {return sin(x);}

    double operator()(double x) const override {return wartosc(x);}

private:

};