#pragma once

#define STATE_TYPE(arg) class arg : public Stan
class MaszynaStanow;

class Stan {
public:
    virtual ~Stan() {}
    virtual void operator()() = 0;
    virtual const char* nazwa() const = 0;
	virtual void podsumowanie() const = 0;

    void setOwner(MaszynaStanow* o) {owner = o;}
    MaszynaStanow* getOwner() {return owner;}

private:
    MaszynaStanow* owner = nullptr;
};