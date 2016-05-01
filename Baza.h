#ifndef BAZA
#define BAZA
#include "Plyta.h"
class Baza 
{	
	char nazwa_;
	public:
		Baza();
		std::vector < Plyta > plyty_;
		
		std::vector < Plyta > wczytajPlyty();
		void wyswietlBaze();
		void zapiszDoPliku();
		void wyszukajPliku(std::string);		
};
#endif