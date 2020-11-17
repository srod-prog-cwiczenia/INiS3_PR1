#include "Zadania.h"
#include "TMenu.h"
//#include "TestKolekcji.h"
#include "FormatowanieKolekcji.h"
void Zadania::przeciazanieOperatorow() {
	/* Zadanie 1:zdefiniowaæ strukturê DaneOsobyStr która
	bêdzie zawieraæ pola: imie, nazwisko, wiek.
	Uwaga: struktura to prawie to samo co klasa które wszystkie
	elementy s¹ domyœlnie public. Wiêc dlaczego w C++ istniej¹ struktury?
	Aby zachowaæ zgodnoœæ z C (w C s¹ struktury).
	Zadanie 2: zdefiniowaæ kontruktor dla tej struktury, metodê toString().
	Zadanie 3: przeci¹¿yæ operator porównania < tak aby
	mo¿na by³o porównywaæ struktury */
	DaneOsobyStr oso0("Dorota", "Kowalska", 20); //konstruktor bezpoœredni
	DaneOsobyStr oso = { "Adam", "Kowalski", 25 }; //konstruktor kopiuj¹cy (dynamiczny)
	/*jak zainicjonwaæ tablicê osób?*/
	DaneOsobyStr osoTab[] = { { "Dorota", "Kowalska", 20},
		{ "Adam", "Kowalski", 25 } };//te¿ konstruktor dynamiczny
	/*uwaga (przetestowaæ to ;) ) s³owo explicit
	  umieszczone przez konstruktorem blokuje
	  funkcjonowanie konstruktorów dynamicznych
	*/
	cout << oso0.toString() << endl;
	cout << oso.toString() << endl;
	for (auto osoL : osoTab)
		cout << osoL.toString() << endl;
	assert(oso0 < oso);
	assert(!(oso < oso0));
	assert(oso >= oso0);
	assert(oso != oso0);
	assert(DaneOsobyStr("Anna", "Kowalska", 18) <= DaneOsobyStr("Anna", "Kowalska", 19));
	assert(!!oso && !!oso0);
	assert(!DaneOsobyStr({ "", "", 0 }));
	/*pierwszy od prawej wykrzyknik to przeci¹¿enie operatora ! na klasê DaneOsobyStr.
	  pierwszy od lewej wykrzyknik to po prostu negacja boolowska */
	cout << endl << "Rzutowanie do typu string:" << (string)oso0 << endl;
	cout << endl << "Dodawanie struktur: " << (string)(oso + oso0) << endl;
}
void Zadania::testyKlasyKolekcja_funkcjaWirtualna()
{
	//std::cout << "Hello World!\n";
// zmienna lokalna
	cout << "TestKolekcji: \n";
	TestKolekcji tk(TRodzajWypelnieniaWektora::rwwDniTygodnia);
	tk.wypisanie();
	cout << endl;

	//wskaŸnik na obiekt:
	cout << "TestKolekcji: \n";
	TestKolekcji* tK = new TestKolekcji(WEKTOR_DNI_TYGODNIA);
	tK->wypisanie();
	delete tK;
	cout << endl;

	//zadanie : wypisaæ liczby 0 - 9 u¿ywaj¹c klasy potomnej:
	//FormatowanieKolekcji:
	cout << "FormatowanieKolekcji: \n";
	FormatowanieKolekcji* fK = new FormatowanieKolekcji(10);
	fK->wypisanie();
	delete fK;
}
void Zadania::testyKlasyKolekcja_typFunkcyjny()
{
	cout << "typ funkcyjny TODO." << endl;
}
void Zadania::testyKlasyKolekcja()
{
	bool koniec = false;
	do {
		TMenu* mnu = new TMenu();
		mnu->addAll(2, "Przez funkcje wirtualne", "Przez typy funkcyjne");
		auto opcja = mnu->wybierz();
		switch (opcja) {
		case 0:
			koniec = true;
			break;
		case 1:
			testyKlasyKolekcja_funkcjaWirtualna();
			break;
		case 2:
			testyKlasyKolekcja_typFunkcyjny();
			break;
		}
	} while (!koniec);
}
;
