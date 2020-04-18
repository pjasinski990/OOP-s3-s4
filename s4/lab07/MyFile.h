#pragma once
#include "MyItem.h"

class MyFile: public MyItem
{
public:
    MyFile(const MyFile& o) = default;
    MyFile(const std::string& name): MyItem(name) {}
    MyFile* clone() const override {return new MyFile(*this);}
    
    MyFile& operator<<(const std::string& s)
    {
        if(!m_data.empty()) {m_data.append("\n");}
        m_data.append(s);
        return *this;
    }
    
    void cat() 
    {
        std::cout << m_data << std::endl;
    }

    void ls(unsigned int op = 0) const override {printName(op);}

private:
    std::string m_data;
};