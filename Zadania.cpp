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

void Zadania::testyKlasyKolekcja_typFunkcyjny()
{
	//cout << "typ funkcyjny TODO." << endl;
	/*lambda funkcje to funkcje ,,lokalne'' */
/*	auto formatujL = [](const string& txt) -> string {
		string res;
		for (auto ch : txt)
			res += toupper(ch);
		return res;
	}; */ // tak si� tworzy zmienn� funkcyjna lokaln�
	TestKolekcji* tk = new TestKolekcji(TRodzajWypelnieniaWektora::rwwDniTygodnia);
	int licznik = 0;
	/*TODO: doda� do funkcji formatuj�cej licznik wierszy - uwaga : rozwi�zanie postaci
	[&licznik] tu nie dzia�a...*/
	tk->setFunkcjaFormatujaca(
		[](const string& txt) -> string {
			string res;
			//int licznik = 1; - tu konstrukcja zastosowana poni�ej do
			//samodzielnej lambda funkcji nie przechodzi
			for (auto ch : txt)
				res += toupper(ch);
			return res;  
		}
	);  
	tk->wypisanie();
	delete tk;
	/* to poni�sze rozwi�zanie dzia�a w przypadku kiedy u�ywamy lambda
	funkcji formatuj�cej samodzielnie: */
	auto funkcjaLicznik = [&licznik](const string& txt) -> string {
		string res;
		for (auto ch : txt)
			res += toupper(ch);
		return to_string(++licznik) + ". " + res;  //zle - b�d� same zera - licznik nie dzia�a....
	};
	licznik = 0;
	cout << string(50, '=') << endl;
	for (int jj = 1; jj < 10; jj++) {
		cout << funkcjaLicznik(" " + to_string(jj)) << endl;
	}
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
void Zadania::rolaModyfikatoraVirtual()
{
	class K1 {
		public:
			virtual int f(int p) {
				return p;
			};
			void oblicz() {
				for (int i : {1, 2, 3, 4, 5}) {
					cout << f(i) << "\t";
				}
				cout << endl;
			}
	};
	class K2 : public K1 {
		public:
			int f(int p) {
				return p * p;
			};
	};
    cout << "Z powodu wirtualno�ci metody ukazuje si� lista kwadrat�w liczb:\n";
	K2* o2 = new K2();
	//((K1*)o2)->oblicz();
	o2->oblicz();
	delete o2;
}

void Zadania::zadaniaZModyfikacjiKolekcji()
{
	//TODO: utworzyc kolekcje lancuchow, przeksztalcic ja za pomoca
	//transform (#include <algorithm>) na lancuchy z duzymi literami
	//teraz to do wykonania!!!:  a potem ze zliczaniem - tu uzy� funktor�w.
	vector<string> inS = { "Merkury", "Wenus", "Ziemia", "Mars", "Jowisz", "Saturn",
      "Uran", "Neptun", "Pluton" };
	//lambda funkcja:
	auto duzeLitery = [](const string& txt) -> string {
		string kopiaStr(txt);
		for (auto &ch : kopiaStr) ch = toupper(ch); 
		/*auto & zamiast auto bo konstrukcja postaci auto ch : kopiaStr
		powoduje �e zmienna ch ,,przebiega'' oczywi�cie wszystkie
		znaki �a�cucha kopiaStr ale jest to zmienna lokalna i jej modyfikacja 
		niczego w �a�cuchu kopiaStr nie zmienia */
		return kopiaStr;
	};
	/*to poni�ej to funktor zliczaj�cy (czyli maj�cy ,,wewn�trzny stan'')*/
	struct ZliczanieFun {
		int licznik;
		ZliczanieFun() : licznik(0) {};
		string operator ()(const string &txt_p) {
			return to_string(++licznik) + ". " + txt_p;
		};
		void reset(int naIle = 0) { licznik = naIle; }; //zb�dna metoda pomocniczna, ale niech b�dzie
	};

	vector<string> outS1(inS.size());
	transform(inS.begin(), inS.end(), outS1.begin(), duzeLitery);
	cout << "Kolekcja przeksztalcona za pomoca lambda funkcji:\n";
	for (auto txt : outS1)
		cout << txt << endl;
	cout << string(50, '=') << endl;

	vector<string> outS2(inS.size());
	transform(inS.begin(), inS.end(), outS2.begin(), ZliczanieFun());
	cout << "Kolekcja przeksztalcona za pomoca funktor�w:\n";
	for (auto txt : outS2)
		cout << txt << endl;
	cout << endl;

	//u�ycie funktora ,,lokalnie'':
	cout << string(50, '+') << endl;
	ZliczanieFun zlicz;
	cout << zlicz("Jeden") << endl;
	cout << zlicz("Dwa") << endl;
	zlicz.reset();
	cout << zlicz("Numeracja od poczatku") << endl;
	cout << string(50, '+') << endl;
};
