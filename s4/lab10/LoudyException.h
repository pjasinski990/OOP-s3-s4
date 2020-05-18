#pragma once
#include "Loudy.h"

/*
 * Exception for LoudyArray class.
 * On destruction deletes LoudyArray passed in constructor.
 */
class LoudyException
{
public:
    /*
     * Constructor. Takes array that is deallocated in *this destructor.
     * @param array array to be deleted
     */
    LoudyException(LoudyArray* array);
    
    ~LoudyException();

private:
    LoudyArray* m_array;
};
