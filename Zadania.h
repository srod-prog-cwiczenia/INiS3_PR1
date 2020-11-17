#pragma once
#include "define.h"
class Zadania
{
public:
	/*struktura DaneOsobyStr to tzw. klasa wewn�trzna, w main programu
odwo�ujemy si� do niej poprzez Zadania::DaneOsobyStr */
	struct DaneOsobyStr {
		string imie, nazwisko;
		unsigned long int wiek;
		DaneOsobyStr(string imie_p, string nazwisko_p,
			unsigned long int wiek_p) : imie
			(imie_p), nazwisko(nazwisko_p), wiek(wiek_p) {};
		string toString() {
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
		bool operator! () {
			return imie.empty() && nazwisko.empty() && !wiek;
		}
		/*przeci��enie operator�w rzutowa�: */
		operator string() {
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
	};
	// metody klasy:
	static void przeciazanieOperatorow();
	static void testyKlasyKolekcja_funkcjaWirtualna();
	static void testyKlasyKolekcja_typFunkcyjny();
	static void testyKlasyKolekcja();
};

