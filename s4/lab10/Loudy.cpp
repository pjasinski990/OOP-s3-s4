#include "Loudy.h"

Loudy::Loudy(const std::string& msg): m_name{msg} 
{
    std::cout << "Laudy " << m_name << " is waking up!" << std::endl;
}

Loudy::~Loudy() 
{
    std::cout << "Laudy " << m_name << " is going to sleep..." << std::endl;
}
