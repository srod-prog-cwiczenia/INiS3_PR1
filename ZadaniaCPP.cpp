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
		TestKolekcji* tK = new TestKolekcji(WEKTOR_DNI_TYGODNIA);
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
	static void sposobyPrzekazywaniaParametru() {
		class Sposoby {
		public:
			static void f1(int i) { //przez wartość
				cout << "Przez wartosc:\n";
				cout << i << endl;
				i += 100;
			}
			static void f2(int* wsk) { //przez wskaźnik (zapożyczenie z języka C)
				cout << "Przez wskaznik:\n";
				cout << *wsk << endl;
				*wsk += 100;
			}
			static void f3(int& i) { // przez zmienną (tylko w C++)
				//jeśli chcemy mieć pewność że nie podmienimy wartości
				//zmiennej i w funkcji to stosujemy static void f3(const int& i) {...
				cout << "Przez zmienna:\n";
				cout << i << endl;
				i += 100;
			}
		};
		int j = 7;
		Sposoby::f1(j);
		cout << j << endl << endl;

		j = 7;
		Sposoby::f2(&j);
		cout << j << endl << endl;

		j = 7;
		Sposoby::f3(j);
		cout << j << endl << endl;
		/*wynik:
		Przez wartosc :   7    7
		Przez wskaznik :  7  107
		Przez zmienna :   7  107 */
	}
	static void przeciazanieOperatorow() {
		/* Zadanie 1:zdefiniować strukturę DaneOsobyStr która
		będzie zawierać pola: imie, nazwisko, wiek.
		Uwaga: struktura to prawie to samo co klasa które wszystkie
		elementy są domyślnie public. Więc dlaczego w C++ istnieją struktury?
		Aby zachować zgodność z C (w C są struktury).
		Zadanie 2: zdefiniować kontruktor dla tej struktury, metodę toString(),*/
		struct DaneOsobyStr {
			string imie, nazwisko;
			unsigned long int wiek;
			DaneOsobyStr(string imie_p, string nazwisko_p, 
				unsigned long int wiek_p) : imie
				(imie_p), nazwisko(nazwisko_p), wiek(wiek_p) {};
			string toString() {
				return "imie: " + imie + "; nazwisko: " + nazwisko
					+ "; wiek: " + to_string(wiek);
			}
		};
		DaneOsobyStr oso0("Dorota", "Kowalska", 20); //konstruktor bezpośredni
		DaneOsobyStr oso = { "Adam", "Kowalski", 25 }; //konstruktor kopiujący (dynamiczny)
		/*jak zainicjonwać tablicę osób?*/
		DaneOsobyStr osoTab[] = { { "Dorota", "Kowalska", 20},
			{ "Adam", "Kowalski", 25 } };//też konstruktor dynamiczny
		/*uwaga (przetestować to ;) ) słowo explicit 
		  umieszczone przez konstruktorem blokuje 
		  funkcjonowanie konstruktorów dynamicznych 
		*/
		cout << oso0.toString() << endl;
		cout << oso.toString() << endl;
		for (auto osoL : osoTab)
			cout << osoL.toString() << endl;
	}
};


int main()
{
	bool koniec = false;
	do {
		TMenu* mnu = new TMenu();
		mnu->addAll(4, "Test klas Kolekcja",
			"Przyklad modyfikatora virtual",
			"Test rodzajow przekazywania argumentu",
			"Przeciazanie operatorow (zadania)");
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
			Zadania::sposobyPrzekazywaniaParametru();
			break;
		case 4:
			Zadania::przeciazanieOperatorow();
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
