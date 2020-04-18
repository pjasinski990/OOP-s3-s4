#pragma once

class MyUnique
{
public:
    MyUnique(MyItem* p): m_p{p} {}
    ~MyUnique()
    {
        delete m_p;
    }
    MyUnique(const MyUnique& o) = delete;
    MyUnique& operator=(const MyUnique& o) = delete;
    MyUnique(MyUnique&& o)
    {
        if(this != &o)
        {
            m_p = o.m_p;
            o.m_p = nullptr;
        }
    }
    MyUnique& operator=(MyUnique&& o)
    {
        if(this != &o) 
        {
            delete m_p;
            m_p = o.m_p;
            o.m_p = nullptr;
        }
        return *this;
    }
    MyItem* get() const {return m_p;}
    
    MyItem* operator->() {return m_p;}
    const MyItem* operator->() const {return m_p;}
    MyItem& operator*() {return *m_p;}
    const MyItem& operator*() const {return *m_p;}
private:
    MyItem* m_p;
};