#pragma once
#include "TestKolekcji.h"
class FormatowanieKolekcji :
	public TestKolekcji
{
public:
	FormatowanieKolekcji(const int ile);//konstruktor
private: 
   string formatowanie(const string &linia);
};

