#include "Stan.h"
#include "ListaString.h"
#include <iostream>
#include <string>
#include <vector>


STATE_TYPE( DostepneSystemy ) {
public:
	DostepneSystemy(ListaString systems)
		: m_systList(std::move(systems))
		, m_selected(0)
	{
		
	}
	
	virtual void operator()() {
		std::cout << "Program mozna uruchomic na nastepujacych systemach: " << std::endl;
		std::cout << m_systList;
		
		//std::cin >> m_selected; 
		m_selected = 1; // <- udajemy wczytywanie danych
		
		std::cout << "wybrano \'" << m_systList[m_selected] << "\'" << std::endl;
	}
	
	virtual const char* nazwa() const { 
		return "DostepneSystemy";
	}
	
	virtual void podsumowanie() const {
		std::cout << " * Wybrano system: \'" << m_systList[m_selected] << "\'" << std::endl;;
	}
	
private:
	ListaString  m_systList;
	unsigned int m_selected;
};

STATE_TYPE( Instalacja ) {
public:
	virtual void operator()() {
		std::cout << "Instalacja w toku... " << std::endl;
		std::cout << "OK!" << std::endl;
	}
	
	virtual const char* nazwa() const { 
		return "Instalacja";
	}
	
	virtual void podsumowanie() const {
		return;
	};
};

STATE_TYPE( ZbieranieDanych ) {
public:
	ZbieranieDanych(const std::string& data): m_data{data} { }

	virtual void operator()() {
		std::cout << "Prosze podac dana: " << m_data << " = ?, podano ";
		// collect data from user
		m_adres = "Nowak@mail.com";
		std::cout << "\'" << m_adres << "\'" << std::endl;
	}

	virtual const char* nazwa() const{
		return "ZbieranieDanych";
	}

	virtual void podsumowanie() const {
		std::cout << " * " << m_data << " = " << m_adres << std::endl;
	}

private:
	std::string m_adres;
	std::string m_data;
};

STATE_TYPE( Podsumowanie ) {
public:
	virtual void operator()() {
		std::cout << "Podsumowanie:" << std::endl;
		for(Stan* s: getOwner()->getStates()) {
			s->podsumowanie();
		}
	}

	virtual const char* nazwa() const{
		return "Podsumowanie";
	}

	virtual void podsumowanie() const {
		return;
	}
};