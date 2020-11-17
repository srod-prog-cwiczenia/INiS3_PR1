#include "Zadania.h"
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
};
