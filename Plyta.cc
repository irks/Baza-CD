#include <string>
#include <vector>
#include <boost/filesystem.hpp>
#include "Plyta.h"
//#include <sstream>

using namespace boost::filesystem;
using namespace std;

extern const path sciezkaProgramu; //sciezka w ktorej znajduje sie program (z pliku Baza.cc)

Plyta::Plyta( path sciezkaPlyty ) {
	wczytajNazwyPlikow( sciezkaPlyty ); //wczytuje nazwy plikow i katalogow na Plycie
    /*std::stringstream temp;
    temp << sciezkaPlyty.filename();*/
	nazwaPlyty_ = /*temp.str()*/sciezkaPlyty.filename().native()/*.generic_string())*//*.string()*/;
}

void Plyta::wczytajNazwyPlikow( const path sciezkaPlyty ) {
	vector < string > nazwyPlikow;
	directory_iterator iterator( sciezkaPlyty );

    for(; iterator != directory_iterator(); ++iterator) {
    	//if( is_regular_file( iterator->path() ) ) {
            /*std::stringstream temp;
            temp << iterator->path().filename();*/
        	nazwyPlikow.push_back(/*temp.str()*/iterator->path().filename().native()/*.generic_string()*/)/*.string()*/ ; //}
    } // petla wczytujaca do vectora nazwy plikow i katalogow na Plycie
    
    pliki_ = nazwyPlikow;
}