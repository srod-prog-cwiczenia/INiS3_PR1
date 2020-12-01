// ZadaniaZCPP.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "Zadania.h"
#include "TestKolekcji.h"
#include "FormatowanieKolekcji.h"
#include "TMenu.h"

class __Zadania : public Zadania {
	//TODO: przenieść wszystkie metody klasy __Zadania do Zadania.cpp
public:
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
		int j;
		for (int sposob = 1; sposob <= 3; sposob++) {
			j = 7;
			switch (sposob) {
			case 1:
				Sposoby::f1(j); break;
			case 2:
				Sposoby::f2(&j); break;
			case 3:
				Sposoby::f3(j); break;
			}
			cout << j << endl << endl;
		}
		/*wynik:
		Przez wartosc :   7    7
		Przez wskaznik :  7  107
		Przez zmienna :   7  107 */
	}
};


int main()
{
	bool koniec = false;
	do {
		TMenu* mnu = new TMenu();
		mnu->addAll(6, "Test klas Kolekcja",
			"Przyklad modyfikatora virtual",
			"Test rodzajow przekazywania argumentu",
			"Przeciazanie operatorow (zadania)",
			"Zadania z automatycznej modyfikacji kolekcji", 
			"Zadanie z obslugi kolekcji set<DaneOsoStr>");
		switch (mnu->wybierz()) {
		case 0:
			koniec = true;
			break;
		case 1:
			Zadania::testyKlasyKolekcja();
			break;
		case 2:
			Zadania::rolaModyfikatoraVirtual();
			break;
		case 3:
			__Zadania::sposobyPrzekazywaniaParametru();
			break;
		case 4:
			__Zadania::przeciazanieOperatorow();
			break;
		case 5:
			Zadania::zadaniaZModyfikacjiKolekcji();
			break;
		case 6: 
			Zadania::zbiorDaneOsoTesty();
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
