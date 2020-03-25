#pragma once

#include <iostream>
#include <vector>
#include <string>

class ListaString {
public:
    ListaString() {
        if (loud) { std::cout << "(list-def-ctor)" << std::endl; }
    }
    ~ListaString() {
        if (loud) { std::cout << "(list-dtor)" << std::endl; }
    }
    ListaString(const ListaString& o) {
        if (loud) { std::cout << "(list-copy-ctor)" << std::endl; }
        m_array = o.m_array;
    }
    ListaString(ListaString&& o) {
        if (loud) { std::cout << "(list-move-ctor)" << std::endl; }
        m_array.clear();
        for(unsigned int i  = 0; i < o.m_array.size(); i++) {
            m_array.push_back(std::move(o.m_array[i]));
        }
    }

    static void rob_halas(bool state) {
        loud = state;
    }
    friend std::ostream& operator<<(std::ostream& ostream, const ListaString& o);
    ListaString& operator<<(const std::string&& s)
    {
        m_array.push_back(std::move(s));
        return *this;
    }
    const std::string& operator[](int i) const
    {
        return m_array[i];
    }
    std::string& operator[](int i)
    {
        return m_array[i];
    }

    static bool loud;
private:
    std::vector<std::string> m_array;
};

std::ostream& operator<<(std::ostream& ostream, const ListaString& o)
{
    int i = 1;
    for (const std::string& o : o.m_array)
    {
        ostream << i << ". " << o << std::endl;
    }
    return ostream;
}

bool ListaString::loud = false;