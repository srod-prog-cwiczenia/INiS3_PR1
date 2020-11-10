#pragma once
#include "define.h"
class TestKolekcji
{
	/*
	* Zadanie:
	* 1. zdefiniwa� typ funkcyjny TFunkcjaFormatowanie
	* 2. zadeklarowa� prywatne pole o rzeczonym typie w tej klasie
	* 3. utorzy� setter do tego pola
	* 4. zaimplementowa� pole w metodzie formatowanie
	* 5. Stworzy� lambda funkcj� formatuj�c� (w jakikolwiek spos�b)
	*    i zastosowa� j� w obiekcie klasy TestKolekcji.
	  uwaga: zmiany wprowadza� tak by nie niszczy�
	  dzia�aj�cego ju� kodu!
	*/
private:
	vector<string> vec;
public:
	TestKolekcji(const int ile); //konstruktor
	TestKolekcji(const char co);  //konstruktor
	TestKolekcji(const TRodzajWypelnieniaWektora co);//konstruktor
	~TestKolekcji(); //destruktor
	void wypisanie();
	virtual string formatowanie(const string &linia);
};

