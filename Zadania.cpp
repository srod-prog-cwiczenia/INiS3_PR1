#include "Zadania.h"
#include "TMenu.h"
//#include "TestKolekcji.h"
#include "FormatowanieKolekcji.h"
//samodzielny szablon:
template <typename T>
class TrzymaczTrojek {
private:
	T p[3];
public:
	TrzymaczTrojek(const T& a1, const T& a2, const T& a3) {
		p[0] = a1;
		p[1] = a2;
		p[2] = a3;
	};
	T getElement(const unsigned int nr) {
		assert(nr <= 3 && nr >= 1 && "Zly indeks w getElement szablonu TrzymaczTrojek");
		return p[nr - 1];
	}
};
/*zadanie - utworzy� szablon symuluj�cy stos typu LIFO */
//-------------------------------------------
template <typename T> // to jest template(=szablon) ale klasy abstrakcyjnej, 
//czyli odpowiednika w C++ interfejsu
class TStosInterface {
	virtual void push(const T& ele) = 0;
	virtual T pop() = 0;
	virtual unsigned int rozmiar() = 0;
};
//-------------------------------------------
template <typename T>
class TStos : public TStosInterface<T> {
private:
	unsigned int licznik = 0;
	struct TElementStr {
		T element; //ewentualnie T* element;
		TElementStr* nastepny;
	};
	TElementStr* korzen = NULL;
public:
	TStos() {};
	~TStos() {
		/* destruktor kt�ry zwalnia pami��
		na wszystkie elementy stosu. CHYBA gdyby u�y� autowska�nik�w.
		*/
		while (licznik > 0)
			pop();
	};
	void push(const T& ele) {
		TElementStr* nowyEle = new TElementStr();
		nowyEle->nastepny = korzen;
		nowyEle->element = ele;
		korzen = nowyEle;
		licznik++;
	};
	T pop() {
		if (licznik == 0) {
			//T dummy = NULL; return dummy;  //, albo mo�e lepiej tak:
			assert(!"Proba zdjecia elementu ze stosu pustego!");
		}
		else {
			T odp = korzen->element;
			TElementStr* doUsuniecia = korzen;
			korzen = korzen->nastepny;
			delete doUsuniecia;
			licznik--;
			return odp;
		}
	}
	unsigned int rozmiar() { return licznik; }
};
//-------------------------------------------
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
	//testy na += i ++:
	DaneOsobyStr osoN = { "Anna", "Kowalska", 25 };
	osoN++;
	assert(osoN.wiek == 26);
	osoN += oso0;
	cout << "Po += : " << (string)osoN << endl;
	/*dodatkowe zadanie nr 4:
prze�adowa� operator << dla DaneOsobyStr tak aby nie trzeba
by�o pisa� cout << (string)oso tylko cout << oso*/
	cout << "A teraz przetestowanie przeladowania "
		"przekierowania do strumienia...: " << osoN << endl;

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
}
void Zadania::zbiorDaneOsoTesty()
{
	/* utworzyc zbior set<DaneOsoStr> i sprawdzic dlaczego
	musi (?) by� prze�adowany operator < */
	set<DaneOsobyStr> zOso;
	zOso.insert(DaneOsobyStr("Anna", "Kowalska", 25));
	zOso.insert(DaneOsobyStr("Anna", "Kowalska", 30));
	zOso.insert(DaneOsobyStr("Dorota", "Nowak", 24));
	zOso.insert(DaneOsobyStr("Dorota", "Nowak", 24)); //specjalnie powt�rzony by sprawdzi� jak si� zachowa set
	zOso.insert(DaneOsobyStr("Artur", "Koralewski", 20));
	cout << "Lista zbioru osob: \n";
	for (const auto &oso : zOso)
		cout << (string)oso << endl;
}
void Zadania::zadaniaZSzablonow()
{
	//tu b�d� zadania z szablon�w...
	bool koniec = false;
	do {
		TMenu* mnu = new TMenu();
		mnu->addAll(2, "Test szablonu TrzymaczTrojek",
			"Test szablonu TStos");
		switch (mnu->wybierz()) {
		case 0:
			koniec = true;
			break;
		case 1: {
			//�wiczenie: zdefiniujemy (utorzymy) szablon ,,trzymacz'' - ,,pojemnik'' - na tr�jki obiekt�w
			TrzymaczTrojek<int> t3 = { 7, 13, 17 };
			TrzymaczTrojek<string> s3 = { "Ala", "ma", "kota" };
			TrzymaczTrojek<DaneOsobyStr> o3 = { {"Anna", "Kowalska", 30},
				{"Dorota", "Nowak", 24 },
				{"Artur", "Koralewski", 20 }
			};
			cout << "Pierwszy element t3: (7): " << t3.getElement(1) << endl;
			cout << "Pierwszy element s3: (Ala): " << s3.getElement(1) << endl;
			cout << "Pierwszy element o3: (Anna Kowalska): " << o3.getElement(1) << endl;
			break;
		}
		case 2: {
			TStos<int> sInt;
			for (int i = 1; i < 20; i += 3)
				sInt.push(i);
			cout << "Elementy stosu int-�w : " << endl;
			while (sInt.rozmiar()) {
				cout << sInt.pop();
				if (sInt.rozmiar())
					cout << "\t";
			}
			cout << endl;

			TStos<DaneOsobyStr> sOso;
			sOso.push(DaneOsobyStr("Anna", "Kowalska", 25));
			sOso.push(DaneOsobyStr("Anna", "Kowalska", 30));
			sOso.push(DaneOsobyStr("Dorota", "Nowak", 24));

			cout << "Elementy stosu struktur DaneOsobyStr: " << endl;
			while (sOso.rozmiar()) {
				cout << sOso.pop();
				if (sOso.rozmiar())
					cout << "\t";
			}
			cout << endl;
			break; 
			/*
			TODO: zauwa�my �e sekwencja kodu wypisuj�cego zawarto�� stosu
			powtarza si� dwukrotnie. Wi�c sugestia aby u�y�
			potomnej klasy TStosExt i tam u�y� prze�adowanego operatora <<
			do typu T.
			TODO: Przepisa� TStos na TStosAuto z wykorzystaniem autowska�nik�w
			*/
		}
		}
		delete mnu;
	} while (!koniec);
}
;
