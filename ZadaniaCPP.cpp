// ZadaniaZCPP.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "TestKolekcji.h"
#include "FormatowanieKolekcji.h"
#include "TMenu.h"

class Zadania {
public:
  static void testKlasKolekcja() {
    //std::cout << "Hello World!\n";
    // zmienna lokalna
	cout << "TestKolekcji: \n";
    TestKolekcji tk(TRodzajWypelnieniaWektora::rwwDniTygodnia);
    tk.wypisanie();
    cout << endl;

	//wskaźnik na obiekt:
	cout << "TestKolekcji: \n";
	TestKolekcji *tK = new TestKolekcji(WEKTOR_DNI_TYGODNIA);
    tK->wypisanie();
    delete tK;
	cout << endl;

    //zadanie : wypisać liczby 0 - 9 używając klasy potomnej:
    //FormatowanieKolekcji:
	cout << "FormatowanieKolekcji: \n";
	FormatowanieKolekcji* fK = new FormatowanieKolekcji(10);
    fK->wypisanie();
    delete fK;
  }
  static void rolaModyfikatoraVirtual() {
  	class K1 {
		public:
			virtual int f(int p) {
				return p;
			};
			void oblicz() {
				for (int i : {1, 2, 3, 4, 5}) {
					cout << f(i) << "\t";
				}
				cout << endl;
			}
		};
		class K2 : public K1 {
		public:
			int f(int p) {
				return p * p;
			};
		};
		cout << "Z powodu wirtualności metody ukazuje się lista kwadratów liczb:\n";
		K2* o2 = new K2();
		//((K1*)o2)->oblicz();
		o2->oblicz();
		delete o2;
  }
};


int main()
{
	bool koniec = false;
	do {
		TMenu* mnu = new TMenu();
		mnu->addAll(3, "Test klas Kolekcja",
			"Przyklad modyfikatora virtual",
			"Test rodzajow przekazywania argumentu");
		switch (mnu->wybierz()) {
		case 0:
			koniec = true;
			break;
		case 1:
			Zadania::testKlasKolekcja();
			break;
		case 2:
			Zadania::rolaModyfikatoraVirtual();
			break;
		case 3:
			cout << "TODO: Zadanie.\n";
			break;
		}
		delete mnu;
	} while (!koniec);
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
