#include "Zadania.h"
#include "TMenu.h"
//#include "TestKolekcji.h"
#include "FormatowanieKolekcji.h"
void Zadania::przeciazanieOperatorow() {
	/* Zadanie 1:zdefiniowa� struktur� DaneOsobyStr kt�ra
	b�dzie zawiera� pola: imie, nazwisko, wiek.
	Uwaga: struktura to prawie to samo co klasa kt�re wszystkie
	elementy s� domy�lnie public. Wi�c dlaczego w C++ istniej� struktury?
	Aby zachowa� zgodno�� z C (w C s� struktury).
	Zadanie 2: zdefiniowa� kontruktor dla tej struktury, metod� toString().
	Zadanie 3: przeci��y� operator por�wnania < tak aby
	mo�na by�o por�wnywa� struktury */
	DaneOsobyStr oso0("Dorota", "Kowalska", 20); //konstruktor bezpo�redni
	DaneOsobyStr oso = { "Adam", "Kowalski", 25 }; //konstruktor kopiuj�cy (dynamiczny)
	/*jak zainicjonwa� tablic� os�b?*/
	DaneOsobyStr osoTab[] = { { "Dorota", "Kowalska", 20},
		{ "Adam", "Kowalski", 25 } };//te� konstruktor dynamiczny
	/*uwaga (przetestowa� to ;) ) s�owo explicit
	  umieszczone przez konstruktorem blokuje
	  funkcjonowanie konstruktor�w dynamicznych
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
	/*pierwszy od prawej wykrzyknik to przeci��enie operatora ! na klas� DaneOsobyStr.
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

	//wska�nik na obiekt:
	cout << "TestKolekcji: \n";
	TestKolekcji* tK = new TestKolekcji(WEKTOR_DNI_TYGODNIA);
	tK->wypisanie();
	delete tK;
	cout << endl;

	//zadanie : wypisa� liczby 0 - 9 u�ywaj�c klasy potomnej:
	//FormatowanieKolekcji:
	cout << "FormatowanieKolekcji: \n";
	FormatowanieKolekcji* fK = new FormatowanieKolekcji(10);
	fK->wypisanie();
	delete fK;
}
// to jest funkcja ,,wisz�ca'' czyli nie
// nale�y do �adnej klasy, �adnego namespace, etc.
string formatujL(string txt) {
	string res;
	for (auto ch : txt)
		res += toupper(ch);
	return res;
}

void Zadania::testyKlasyKolekcja_typFunkcyjny()
{
	//cout << "typ funkcyjny TODO." << endl;
	TestKolekcji* tk = new TestKolekcji(TRodzajWypelnieniaWektora::rwwDniTygodnia);
	tk->setFunkcjaFormatujaca(formatujL);
	tk->wypisanie();
	delete tk;
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
