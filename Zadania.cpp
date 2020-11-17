#include "Zadania.h"
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
};
