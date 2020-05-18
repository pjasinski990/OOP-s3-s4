#pragma once
#include "LoudyArray.h"
#include <iostream>

/*
 * Dummy class with loud constructor and destructor.
 */
class Loudy
{
public:
    Loudy(const std::string& msg);
    
    ~Loudy();
    
    /*
     * Skip to nearest catch
     */
    void skip() {throw m_name;}

private:
    std::string m_name;
};
