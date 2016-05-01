#include "Baza.h"
#include "Plyta.h"
#include <vector>
#include <boost/filesystem.hpp>
#include <iostream>
#include <fstream>
using namespace boost::filesystem;
using namespace std;
const path sciezkaProgramu ("../..");
Baza::Baza() {
	plyty_ = wczytajPlyty();
	wyswietlBaze();
	zapiszDoPliku();
	wyszukajPliku("gi");
}

vector < Plyta > Baza::wczytajPlyty() {
	vector < Plyta > plyty;
	directory_iterator iterator(sciezkaProgramu);
	for(; iterator != directory_iterator(); ++iterator) {
    	if(is_directory(iterator->path())) {
        	plyty.push_back(Plyta(iterator->path()));
        }
    }
    return plyty;
}

void Baza::wyswietlBaze() {
	for(int i=0; i<plyty_.size(); ++i) {
		cout << "----------------" << endl;
		cout << plyty_[i].nazwaPlyty_ << endl;
		cout << "----------------" << endl;
		for(int j=0; j<plyty_[i].pliki_.size(); ++j) {
			cout << ((plyty_[i]).pliki_[j]) << endl;
		}
	}
}

void Baza::zapiszDoPliku() {
	ofstream plikBazy;
	plikBazy.open("Baza_plyt_CD")/*("abc", std::ios::in | std::ios::out)*/;
	if( plikBazy.good() == true ) {
    	cout << "Uzyskano dostep do pliku!" << endl;
    	
    	for(int i=0; i<plyty_.size(); ++i) {
			
			plikBazy << "/" <<plyty_[i].nazwaPlyty_ << endl;
		
			for(int j=0; j<plyty_[i].pliki_.size(); ++j) {
				plikBazy << ((plyty_[i]).pliki_[j]) << endl;
			}	
		}
		plikBazy.close();
	} 
	else 
		cout << "Dostep do pliku zostal zabroniony!" << endl;
}

void Baza::wyszukajPliku(string szukany) {
	string nazwaPlikuBazy = "Baza_plyt_CD";
	fstream plikBazy(nazwaPlikuBazy.c_str(), ios::in | ios::out);
	string dana;
	string aktualnyKatalog;
	while(!plikBazy.eof()) {
		if(plikBazy.peek() != '/') {
			getline(plikBazy, dana);
			if(dana.find(szukany) != std::string::npos) {
				cout<< aktualnyKatalog << "/" << dana <<endl;
			}
		}
		else {
			plikBazy.get();
			getline(plikBazy, aktualnyKatalog);
		}
	}
}
