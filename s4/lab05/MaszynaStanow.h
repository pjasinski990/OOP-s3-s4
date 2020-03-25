#pragma once

#include <iostream>
#include <memory>
#include "Stan.h"

class MaszynaStanow {
public:
    MaszynaStanow(): m_currentState{0} { }
    ~MaszynaStanow() {
        for( Stan* s: m_statesList) {
            delete s;
        }
    }
    const std::vector<Stan*>& getStates() {return m_statesList;}

    Stan& operator()() const {
        return *m_statesList[m_currentState];
    }

    void operator++() {
        ++m_currentState;
    }
    void operator--() {
        --m_currentState;
    }

    MaszynaStanow& operator+=(Stan* qs) {
        m_statesList.push_back(qs);
        qs->setOwner(this);
        return *this;
    }
    
    friend std::ostream& operator<<(std::ostream& ostream, const MaszynaStanow& o);

    void start() {
        std::cout << "Rozpoczynamy dzialanie maszyny stanow!" << std::endl;
    }
private:
    std::vector<Stan*> m_statesList;
    unsigned int m_currentState;
};

std::ostream& operator<<(std::ostream& ostream, const MaszynaStanow& o) {
    for(unsigned int i = 0; i < o.m_statesList.size(); i++) {
        if (i == o.m_currentState)
        {
            ostream << " >" << o.m_statesList[i]->nazwa() << "< ";
        }
        else
        {
            ostream << o.m_statesList[i]->nazwa() << " ";
        }
    }
    return ostream;
}