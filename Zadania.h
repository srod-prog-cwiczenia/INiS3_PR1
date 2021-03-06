#pragma once
#include "define.h"
struct DaneOsobyStr {
	string imie, nazwisko;
	unsigned long int wiek;
	DaneOsobyStr() : wiek(0) {};
	DaneOsobyStr(const string& imie_p, const string& nazwisko_p,
		const unsigned long int& wiek_p) : imie
		(imie_p), nazwisko(nazwisko_p), wiek(wiek_p) {};
	string toString() const {
		return "imie: " + imie + "; nazwisko: " + nazwisko
			+ "; wiek: " + to_string(wiek);
	}
	//rozwi�zanie zadania 3 - przeci��enia operator�w por�wna�: <,>,==,!=,<=,>=:
	friend bool operator<(const DaneOsobyStr& a, const DaneOsobyStr& b) {
		if (a.nazwisko < b.nazwisko) return true;
		if (a.nazwisko > b.nazwisko) return false;
		if (a.imie < b.imie) return true;
		if (a.imie > b.imie) return false;
		if (a.wiek < b.wiek) return true;
		if (a.wiek > b.wiek) return false;
		return false;
	}
	friend bool operator>=(const DaneOsobyStr& a, const DaneOsobyStr& b) {
		return !(a < b);
	}
	friend bool operator==(const DaneOsobyStr& a, const DaneOsobyStr& b) {
		return a.nazwisko == b.nazwisko && a.imie == b.imie && a.wiek == b.wiek;
		//mog�o by� te� tak: return !(a < b) && !(b < a);
	}
	friend bool operator!=(const DaneOsobyStr& a, const DaneOsobyStr& b) {
		return !(a == b);
	}
	friend bool operator >(const DaneOsobyStr& a, const DaneOsobyStr& b) {
		return a >= b && a != b;
	}
	friend bool operator <= (const DaneOsobyStr& a, const DaneOsobyStr& b) {
		return a < b || a == b;
	}
	/*przeci��enie operatora negacji: */
	bool operator! () const {
		return imie.empty() && nazwisko.empty() && !wiek;
	}
	/*przeci��enie operator�w rzutowa�: */
	operator string() const {
		return toString();
	}
	/* przeci��enie operator�w dodawania: + oraz += */
	friend DaneOsobyStr operator + (const DaneOsobyStr& a, const DaneOsobyStr& b) {
		return DaneOsobyStr(a.imie + b.imie,
			a.nazwisko + b.nazwisko,
			a.wiek + b.wiek
		);
	}
	friend DaneOsobyStr operator += (DaneOsobyStr& a, const DaneOsobyStr& b) {//a += b
		a = a + b;
		return a;
	}
	/* zadanie domowe: napisa� przeci��enie (=,,prze�adowanie'')
	operatora ++ i -- (niech tylko zwi�ksza lub zmniejsza wiek o 1) */
	DaneOsobyStr& operator ++() { wiek++; return *this; }; //prefiksowy
	DaneOsobyStr operator ++(int) {
		DaneOsobyStr pom = *this;
		++(*this);
		return pom;
	}; //postfiksowy
	/* rozwi�zanie zadania nr 4: prze�adowanie operatora << (przekierowanie do strumienia) */
	/*ostream& operator << (ostream& strumien) {
		strumien << (string)(*this);
		return strumien;
	}*/
	friend ostream& operator << (ostream& strumien, const DaneOsobyStr &a) {
		strumien << (string)a;
		return strumien;
	}
};

class Zadania
{
public:
	/*struktura DaneOsobyStr by�a klas� wewn�trzn� klasy Zadania
	(czyli w main programu odwo�ywali�my si� do niej poprzez Zadania::DaneOsobyStr ),
	jednak aby unikn�� k�opot�w z parserem programu w edytorze zosta�a
	wydzielona jako samodzielna, */
	// metody klasy:
	static void przeciazanieOperatorow();
	static void testyKlasyKolekcja_funkcjaWirtualna();
	static void testyKlasyKolekcja_typFunkcyjny();
	static void testyKlasyKolekcja();
	static void rolaModyfikatoraVirtual();
	static void zadaniaZModyfikacjiKolekcji();
	static void zbiorDaneOsoTesty();
	static void zadaniaZSzablonow();
};

