// Wrobel Ireneusz, Informatyka, grupa 2I5
// Program sluzacy do tworzenia i obslugi bazy danych o kolekcji programow i plikow
// Klasa przechowujaca wektor obiektow klasy Plyta oraz operujaca na tych danych

#ifndef BAZA_H
#define BAZA_H

#include "Plyta.h"
#include <string>

class Baza { //domyslnie private	
	std::vector < Plyta > plyty_;  

	public:
		void wczytajPlyty(  ); //do atrybutu plyty_ wczytuje katalogi w biezacym katalogu
		int ilePlyt(  );
		bool zapiszDoPliku( std::string ); //zapisuje baze w pliku
		std::vector < std::string > wyszukajPliku( const std::string &, std::string & );
		std::vector < std::string > wyswietlAktualnaBaze( void );	
};
#endif
