#pragma once
#include "MyPrintable.h"
#include "Attributes.h"

/*
 * Class for storing and printing text.
 * Can have color and format.
 */
class MyText: public MyPrintable, public AttFormat, public AttColor
{
public:
    MyText(const char* text, AttFormat::Attribute format, AttColor::Attribute color):
            AttFormat(format),
            AttColor(color),
            m_text{text}
    {
        
    }
    
    std::string rawString() const override
    {
        return m_text;
    }
    
    void setText(const char* text) {m_text = std::string(text);}
private:
    std::string m_text;
};