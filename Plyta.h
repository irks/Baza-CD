#ifndef PLYTA
#define PLYTA
#include <string>
#include <vector>
#include <boost/filesystem.hpp>
class Plyta {		
	public:
		Plyta(boost::filesystem::path);	
		std::vector < std::string > pliki_;
		std::string nazwaPlyty_;
		
		std::vector < std::string > wczytajNazwyPlikow(boost::filesystem::path);
};
#endif