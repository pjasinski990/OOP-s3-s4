#pragma once
#include "Fun.h"

/*
 * Simple class for creating and handling composite functions.
 * Used with Fun class.
 */
class FZlozona: public Fun
{
private:
    Fun* m_f;
    Fun* m_g;
    
public:
    FZlozona(): m_f{nullptr}, m_g{nullptr} {}
    FZlozona(const FZlozona& o): m_f{o.m_f->clone()}, m_g{o.m_g->clone()} {}
    FZlozona(Fun* f, Fun* g): m_f{f->clone()}, m_g{g->clone()} {}
    ~FZlozona()
    {
        delete(m_f); 
        delete(m_g);
    }
    
    virtual double wartosc(double x) const override {return (*m_g)((*m_f)(x));}

    virtual double operator()(double x) const override {return wartosc(x);}

    virtual Fun* clone() const {return new FZlozona(*this);}
};