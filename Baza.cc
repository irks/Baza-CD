// Wrobel Ireneusz, Informatyka, grupa 2I5
// Program sluzacy do tworzenia i obslugi bazy danych o kolekcji programow i plikow

#include <vector>
#include <boost/filesystem.hpp>
#include <fstream>
#include "Baza.h"
#include "Plyta.h"

using namespace boost::filesystem;
using namespace std;

const path sciezkaProgramu = current_path(); //sciezka w ktorej jest program

void Baza::wczytajPlyty( void ) {
	vector < Plyta > plyty;
	directory_iterator iterator( sciezkaProgramu );

	for(; iterator != directory_iterator(); ++iterator) {
    		if( is_directory( iterator->path() ) ) 
        		plyty.push_back( Plyta( iterator->path() ) ); 
        }

    plyty_ = plyty;
}

bool Baza::zapiszDoPliku( string nazwaPlikuBazy ) {
	ofstream plikBazy;
	plikBazy.open( nazwaPlikuBazy.c_str() );

	if( plikBazy.good() == true ) {	//jezeli udalo sie otworzyc plik tekstowy o podanej nazwie
    	for( int i = 0; i < plyty_.size(); ++i ) {
			plikBazy << "/" << plyty_[i].nazwaPlyty_ << endl; //przed nazwa Plyty w pliku tekstowym znak '/'

			for( int j = 0 ; j < plyty_[i].pliki_.size(); ++j) 
				plikBazy << ( plyty_[i] ).pliki_[j] << endl;
		}
		plikBazy.close();
		return true; //przekazanie ze udalo sie zapisac baze do pliku tekstowego
	} 
	else 
		return false; //przekazanie ze nie udalo sie otworzyc pliku tekstowego	
}

vector < string > Baza::wyszukajPliku( const string &szukany, string &nazwaPlikuBazy ) {
	fstream plikBazy;
	plikBazy.open( nazwaPlikuBazy.c_str(), ios::in  );
	vector < string > znalezionePliki;

	if( plikBazy.good() == true ) {
		string dana;
		string aktualnyKatalog;

		znalezionePliki.push_back( "1" ); //pierwszy element "1" jezeli udalo sie otworzyc plik

		while( !plikBazy.eof() ) {
			if( plikBazy.peek() != '/' ) { //sprawdzanie czy dany wiersz tekstu nie jest nazwa Plyty
				getline( plikBazy, dana );

				if( dana.find( szukany ) != std::string::npos ) 
					znalezionePliki.push_back( aktualnyKatalog + "/" + dana );
			}
			else { //jezeli dany wiersz tekstu to nazwa Plyty
				plikBazy.get();
				getline( plikBazy, aktualnyKatalog );
			}
		}	
	}
	else 
		znalezionePliki.push_back( "0" ); //pierwszy element "0" jezeli nie udalo sie otworzyc plik

	return znalezionePliki;
}

int Baza::ilePlyt( void ) {
	return plyty_.size();
}

vector < string > Baza::wyswietlAktualnaBaze( void ) {
	vector < string > wszystkiePliki;

	for( int i = 0; i < plyty_.size(); ++i) {	
		for(int j = 0; j < plyty_[i].pliki_.size(); ++j) 
			wszystkiePliki.push_back( plyty_[i].nazwaPlyty_ + "/" +  ( plyty_[i] ).pliki_[j] );
	}
	return wszystkiePliki;
}
