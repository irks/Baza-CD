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
		void wczytajNazwyPlikow( const boost::filesystem::path ); //wczytuje nazwy plikow i katalogow na Plycie
};
#endif