#pragma once
#include <iostream>

/*
 * Simple class calculating number of its instances.
 * Uses static counter incremented in constructor and decremented in destructor.
 * Prints current 'level' on costruction and destruction.
 */
class LicznikPoziomow
{
public:
    LicznikPoziomow() {std::cout << "Rozpoczynamy poziom numer " << ++m_counter << "." << std::endl;}
    ~LicznikPoziomow() {std::cout << "Konczymy poziom numer " << m_counter-- << "." << std::endl;}
    
private:
    static int m_counter;
};

int LicznikPoziomow::m_counter = 0;