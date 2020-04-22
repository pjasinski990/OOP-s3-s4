#pragma once
#include <iostream>

/*
 * Abstract class used as interface for printing in MyPrinter
 */
class MyPrintable
{
public:
    /*
     * Used to output contained string.
     * Overriden by containers.
     *
     * @return std::string string to be printed
     */
    virtual std::string rawString() const = 0;
};