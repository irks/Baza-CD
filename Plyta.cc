// Wrobel Ireneusz, Informatyka, grupa 2I5
// Program sluzacy do tworzenia i obslugi bazy danych o kolekcji programow i plikow

#include <string>
#include <vector>
#include <boost/filesystem.hpp>
#include "Plyta.h"

using namespace boost::filesystem;
using namespace std;

extern const path sciezkaProgramu; //sciezka w ktorej znajduje sie program (z pliku Baza.cc)

Plyta::Plyta( path sciezkaPlyty ) {
	wczytajNazwyPlikow( sciezkaPlyty ); //wczytuje nazwy plikow i katalogow na Plycie
	nazwaPlyty_ = string( sciezkaPlyty.filename() );
}

void Plyta::wczytajNazwyPlikow( const path & sciezkaPlyty ) {
	vector < string > nazwyPlikow;
	directory_iterator iterator( sciezkaPlyty );

        for(; iterator != directory_iterator(); ++iterator) 
        	nazwyPlikow.push_back( string( iterator-> path().filename() ) );
        	// petla wczytujaca do vectora nazwy plikow i katalogow na Plycie

        pliki_ = nazwyPlikow;
}
