#pragma once
class Loudy;

/*
 * Array wrapper for Loudy class.
 */
class LoudyArray
{
public:
    /*
     * Constructs array of passed size.
     * @param size to be allocated
     */
    LoudyArray(int size);
    
    ~LoudyArray();
    
    /*
     * Sets index to passed object pointer. If index was used before,
     * deallocates old object.
     * If index is out of array bonds throws LoudyException.
     */
    void set(int index, Loudy* o);
    
    private:
    int m_size;
    Loudy** m_array;
    
};
