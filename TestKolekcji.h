#pragma once
#include "define.h"
class TestKolekcji
{
private:
	vector<string> vec;
public:
	TestKolekcji(const int ile); //konstruktor
	TestKolekcji(const char co);  //konstruktor
	TestKolekcji(const TRodzajWypelnieniaWektora co);//konstruktor
	~TestKolekcji(); //destruktor
	void wypisanie();
	string formatowanie(const string &linia);
};

