#include "LoudyArray.h"
#include "LoudyException.h"

LoudyArray::LoudyArray(int size): m_size{size}
{
    m_array = new Loudy*[m_size];
    for (int i = 0; i < m_size; i++)
    {
        m_array[i] = nullptr;
    }
}

LoudyArray::~LoudyArray()
{
    for (int i = 0; i < m_size; i++)
    {
        delete m_array[i];
    }
    delete[] m_array;
}

void LoudyArray::set(int index, Loudy* o)
{
    if (index < m_size)
    {
        if (m_array[index])
        {
            delete m_array[index];
        }
        m_array[index] = o;
    }
    else
    {
        delete o;
        throw LoudyException(this);
    }
}
