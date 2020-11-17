#include "TestKolekcji.h"

TestKolekcji::TestKolekcji(const int ile)
{  //konstruktor
	for (int i = 0; i < ile; i++) {
		vec.push_back(to_string(i));
		//vec.push_back("" + i); - ta konstrukcja dzia�aj�ca w Java 
		//nie funkcjonuje w C++
	}

	//albo taka konstrukcja, zapo�yczona z C (nieczytelna,
	//ale do�� zwarta):
	//for (int i = 0; i < ile; vec.push_back(to_string(i++)));
}

TestKolekcji::TestKolekcji(const char co)
{
	switch (co) {
	case WEKTOR_DNI_TYGODNIA:
		// wype�niamy nazwami dni tygodnia
		for (string txt : {"Po", "Wt",
			"�r", "Czw", "Pi�", "So", "Nie"
		})
			vec.push_back(txt);
		break;
	case WEKTOR_LICZBY:
		//wype�niamy liczbami
		break;
	default:
		break;
	}
}

TestKolekcji::TestKolekcji(const TRodzajWypelnieniaWektora co)
{
	switch (co) {
	case TRodzajWypelnieniaWektora::rwwDniTygodnia: 
		for (string txt : {"Po", "Wt",
			"�r", "Czw", "Pi�", "So", "Nie"
		})
			vec.push_back(txt);
		break;
	case TRodzajWypelnieniaWektora::rwwLiczby:
		break;
	}
}

TestKolekcji::~TestKolekcji()
{
	//destruktor - pusty na razie
}

void TestKolekcji::wypisanie()
{
	for (string txt : vec) {
		cout << formatowanie(txt) << endl;
	}
}

string TestKolekcji::formatowanie(const string &linia)
{
	if (funFormat == NULL) {
		return linia;
	}
	else {
		return funFormat(linia);
	}
}

void TestKolekcji::setFunkcjaFormatujaca(TFunkcjaFormatowanie fun_p)
{
	funFormat = fun_p;
}

