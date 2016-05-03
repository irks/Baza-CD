#include <iostream>
#include <vector>
#include "Baza.h"
#include "Plyta.h"

using namespace std;

int main() {
    bool menu = true;
    int wybor; 
    string wyszukiwane; 
    string nazwaPlikuBazy;
    vector < string > znalezionePliki;
    Baza* baza = new Baza();

    while( menu ) {
        cout << endl << endl;
        cout << "===================================================================" << endl;
        cout << "Jaka operacje chcesz wykonac? Wcisnij odpowiedni numer" << endl;
        cout << "1. Stworzyc baze wlozonych plyt CD i zapisac ja do pliku tekstowego" << endl;
        cout << "2. Wyszukac plik w bazie" << endl;
        cout << "9. Wyjsc z programu" << endl;
        cout << "===================================================================" << endl;

        cin >> wybor;

        for( int i = 0; i < 60; ++i )
            cout << endl; //czyszczenie ekranu

        switch( wybor ) {
            case 1: 
                cout << "Podaj nazwe pliku w ktorym chcesz zapisac baze plyt CD" << endl;
                cin >> nazwaPlikuBazy;

                baza-> wczytajPlyty();

                cout << endl;

                if( baza-> zapiszDoPliku( nazwaPlikuBazy ) ) { //jezeli udalo sie otworzyc plik i zapisac
                    cout << "Zapisano baze plyt CD do pliku: " << nazwaPlikuBazy << endl; 
                    cout << "Liczba plyt: " << baza-> ilePlyt() << endl;
                }
                else // wystapil blad przy probie otwarcia pliku
                    cout << "Nie udalo sie utworzyc pliku o podanej nazwie!" << endl;
                break;
            case 2:
                cout << "Podaj nazwe pliku w ktorym zapisana jest baza plyt" << endl;
                cin >> nazwaPlikuBazy;

                cout << "Teraz podaj nazwe pliku ( lub jej fragment ) ktory chcesz znalezc" << endl;
                cin >> wyszukiwane;
               
                znalezionePliki = baza-> wyszukajPliku( wyszukiwane, nazwaPlikuBazy );

                cout << endl;
                
                if( znalezionePliki[0] == "1") { //jezeli udalo sie otworzyc plik o podanej nazwie
                    cout << "Liczba znalezionych plikow: " << znalezionePliki.size() - 1 << endl << endl;
                    
                    for( int i = 1; i < znalezionePliki.size(); ++i )
                        cout << znalezionePliki[i] << endl;
                }
                else if( znalezionePliki[0] == "0" ) //jezeli nie udalo sie otworzyc pliku o podanej nazwie
                    cout << "Nie udalo sie otworzyc pliku o podanej nazwie! Upewnij sie ze plik o podanej nazwie istnieje" << endl;
                
                break;
            case 9:
                menu = false;
                break;
            default: 
                cout << "Musisz podac numer odpowiadajacy danemu dzialaniu!" << endl;
                break;
        }
    }
    return 0;
}