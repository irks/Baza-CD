#ifndef BAZA_H
#define BAZA_H

#include "Plyta.h"
#include <string>

class Baza { //domyslnie private	
	std::vector < Plyta > plyty_;  

	public:
		void wczytajPlyty( void ); //do atrybutu plyty_ wczytuje katalogi w biezacym katalogu
		int ilePlyt( void );
		bool zapiszDoPliku( std::string ); //zapisuje baze w pliku
		std::vector < std::string > wyszukajPliku( const std::string, std::string );	
};
#endif