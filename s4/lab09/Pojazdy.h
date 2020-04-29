#pragma once

/*
 * Generic vehicle class. Contains plate number and string type of vehicle.
 * Vehicle type should be set in inheriting classes.
 */
class Pojazd
{
public:
    Pojazd() = default;
    virtual ~Pojazd() = default;
    
    Pojazd(const std::string& plate): 
            m_type{"Pojazd"}, 
            m_plate{plate} 
    {}

    std::string toString() const {return m_type + " <" + m_plate + ">";}
    
protected:
    std::string m_type;
    
private:
    std::string m_plate;
};

std::ostream& operator<<(std::ostream& out, const Pojazd& o)
{
    out << o.toString();
    return out;
}

/*
 * "Land vehicle" class. Currently used only as a label as it iherits virtually.
 */
class PojazdLadowy: public virtual Pojazd
{};

/*
 * Car class. Additionaly contains maximum speed.
 */
class Samochod: public PojazdLadowy
{
public:
    Samochod(const std::string& plate, const PredkoscMaksymalna& vmax):
            Pojazd(plate), 
            m_vmax{vmax}
    {
        m_type = "Samochod";
    }
    
    const PredkoscMaksymalna& predkoscMaksymalna() const {return m_vmax;}
    
private:
    PredkoscMaksymalna m_vmax;
};

/*
 * Motorboat class. Additionaly contains maximum speed.
 */
class Motorowka: public virtual Pojazd
{
public:
    Motorowka(const std::string& plate, const PredkoscMaksymalna& vmax): 
            Pojazd(plate),
            m_vmax{vmax}
    {
        m_type = "Motorowka";
    }
    
    const PredkoscMaksymalna& predkoscMaksymalna() const {return m_vmax;}
    
private:
    PredkoscMaksymalna m_vmax;
};

class Rower: public PojazdLadowy
{
public:
    Rower(const std::string plate): 
            Pojazd(plate)
    {
        m_type = "Rower";
    }
};

/*
 * Car-boat class that extends both car and motorboat. Thanks to that is
 * has two types of max speed: speed on land and speed on water.
 */
class Amfibia: public Samochod, public Motorowka
{
public:
    Amfibia(const std::string plate, const PredkoscMaksymalna& vland, const PredkoscMaksymalna vwater):
            Pojazd(plate),
            Samochod{plate, vland},
            Motorowka{plate, vwater}
    {
        m_type = "Amfibia";
    }

    const PredkoscMaksymalna& predkoscMaksymalna_Lad() const {return Samochod::predkoscMaksymalna();}
    const PredkoscMaksymalna& predkoscMaksymalna_Woda() const {return Motorowka::predkoscMaksymalna();}
};
