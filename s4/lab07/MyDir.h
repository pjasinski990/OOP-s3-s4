#pragma once
#include "MyItem.h"
#include "MyUnique.h"
#include <vector>

class MyDir: public MyItem
{
public:
    MyDir(const std::string& name): MyItem(name) {}
    ~MyDir();   // defined in main
    MyDir(const MyDir& o): MyItem(o)
    {
        for(auto&& o: o.m_contents)
        {
            MyUnique newq = MyUnique(o->clone());
            m_contents.push_back(std::move(newq));
        }
    }

    MyDir(MyDir&& o): MyItem(o)
    {
        for(auto&& o: o.m_contents)
        {
            m_contents.push_back(std::move(o));
        }
        o.m_contents.clear();
    }

    MyDir* clone() const override { return new MyDir(*this);}
    
    void operator/=(MyUnique&& f)
    {
        m_contents.push_back(std::move(f));
    }

    void ls(unsigned int op = 0) const override 
    {
        printName(op, '/');
        for (auto&& o: m_contents) 
        {
            o->ls(op+1);
        }
    }
private:
    std::vector<MyUnique> m_contents;
};