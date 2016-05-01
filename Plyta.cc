#include "Plyta.h"
#include <iostream>
#include <string>
#include <vector>
#include <boost/filesystem.hpp>
using namespace boost::filesystem;
using namespace std;

extern const path sciezkaProgramu;
Plyta::Plyta( path sciezkaPlyty) {
	pliki_ = wczytajNazwyPlikow(sciezkaPlyty);
	nazwaPlyty_= sciezkaPlyty.filename().string();
}

vector < string > Plyta::wczytajNazwyPlikow(path sciezkaP) {
	vector < string > nazwyPlikow;
	directory_iterator iterator(sciezkaP);
    for(; iterator != directory_iterator(); ++iterator) {
    	if(is_regular_file(iterator->path()))
        	nazwyPlikow.push_back(iterator->path().filename().string());
    }
    return nazwyPlikow;
}