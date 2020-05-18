#include "LoudyException.h"

LoudyException::LoudyException(LoudyArray* array): m_array{array}
{}

LoudyException::~LoudyException()
{
    delete m_array;
}
