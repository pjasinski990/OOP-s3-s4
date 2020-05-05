#pragma once
#include <ostream>

/*
 * Wrapper class for int. Represents max speed of a vehicle provided in km/h.
 * Printing to stream returns stored speed with unit.
 */
class PredkoscMaksymalna
{
public:
    PredkoscMaksymalna(int v): m_vmax{v} {}
    int getSpeed() const {return m_vmax;}
private:
    int m_vmax;
};

std::ostream& operator<<(std::ostream& out, const PredkoscMaksymalna& o)
{
    out << o.getSpeed() << " km/h";
    return out;
}