#include <iostream>
#include "Baza.h"
#include "Plyta.h"
#include <vector>
#include <boost/filesystem.hpp>

using namespace boost::filesystem;
using namespace std;

bool menu=true;

int main() {
    int wybor;
    string wyszukiwane;
    Baza* baza1 = new Baza();

    while(menu) {
        cout << "============================" << endl;
        cout << "Jaka operacje chcesz wykonac? Wcisnij odpowiedni numer" << endl;
        cout << "1. Stworzyc baze wlozonych plyt CD i zapisac ja do pliku tekstowego" << endl;
        cout << "2. Wyszukac plik w bazie" << endl;
        cout << "9. Wyjsc z programu" << endl;
        cout << "===============================" << endl;

        cin >> wybor;
        switch(wybor) {
            case 1: 
                baza1->zapiszDoPliku();
                baza1->wyswietlBaze();
                break;
            case 2:
                cin >> wyszukiwane;
                baza1->wyszukajPliku(wyszukiwane);
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