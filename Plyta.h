// Wrobel Ireneusz, Informatyka, grupa 2I5
// Program sluzacy do tworzenia i obslugi bazy danych o kolekcji programow i plikow
// Klasa zawierajaca nazwy plikow, katalogow na danej Plycie

#ifndef PLYTA_H
#define PLYTA_H

#include <string>
#include <vector>
#include <boost/filesystem.hpp>

class Plyta { //domyslnie private
	std::vector < std::string > pliki_; //nazwy plikow i katalogow na Plycie
	std::string nazwaPlyty_;	
	friend class Baza;	

	public:
		Plyta( boost::filesystem::path ); //argumentem jest sciezka Plyty	
		void wczytajNazwyPlikow( const boost::filesystem::path & ); //wczytuje nazwy plikow i katalogow na Plycie
};
#endif
