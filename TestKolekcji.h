#pragma once
#include "define.h"
class TestKolekcji
{
	/*
	* Zadanie:
	* 1. zdefiniwaæ typ funkcyjny TFunkcjaFormatowanie
	* 2. zadeklarowaæ prywatne pole o rzeczonym typie w tej klasie
	* 3. utorzyæ setter do tego pola
	* 4. zaimplementowaæ pole w metodzie formatowanie
	* 5. Stworzyæ lambda funkcjê formatuj¹c¹ (w jakikolwiek sposób)
	*    i zastosowaæ j¹ w obiekcie klasy TestKolekcji.
	  uwaga: zmiany wprowadzaæ tak by nie niszczyæ
	  dzia³aj¹cego ju¿ kodu!
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

