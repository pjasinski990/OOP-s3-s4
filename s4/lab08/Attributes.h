#pragma once

/*
 * Color attribute class for use with Printable containers.
 * Uses enum of possible colors that is interpreted by MyPrinter::controlSeq
 */
class AttColor 
{
public:
    enum Attribute { BLACK, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, GRAY, WHITE, DEFAULT };
    
    AttColor(Attribute color): m_color{color} 
    {
        
    }

    void setColor(Attribute color) {m_color = color;}
    
    Attribute getColor() const {return m_color;}
    
private:
    Attribute m_color;
};

/*
 * Format attribute class for use with Printable containers.
 * Uses enum of possible formats that is interpreted by MyPrinter::controlSeq
 */
class AttFormat
{
public:
    enum Attribute { BOLD, DIM, UNDERLINED, NORMAL };
    
    AttFormat(Attribute format): m_format{format} 
    {
        
    }
    
    void setFormat(Attribute format) {m_format = format;}
    Attribute getFormat() const {return m_format;}

private:
    Attribute m_format;
};