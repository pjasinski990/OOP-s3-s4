#pragma once
#include "MyPrintable.h"
#include "Attributes.h"

/*
 * Class for storing simple one char line of set length.
 * Can be colored, cannot be formatted.
 */
class MyLine: public MyPrintable, public AttColor
{
public:
    MyLine(char c, int length, AttColor::Attribute color):
            AttColor(color),
            m_char{c},
            m_length{length}
    {}
    
    std::string rawString() const override 
    {
        return std::string(m_length, m_char);
    }
    
    void setChar(char c) {m_char = c;}
    void setLength(int len) {m_length = len;}

private:
    char m_char;
    int m_length;
};