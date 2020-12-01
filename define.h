#pragma once
#include <string>
//inkludy czterech najczêœciej (?) u¿ywanych kolekcji w C++:
#include <vector>
#include <set>
#include <list>
#include <map>
#include <iostream>
#include <cstdarg>
#include <assert.h>
#include <algorithm>

using namespace std;
//stary styl zapo?yczony z j?zyka C:
#define WEKTOR_DNI_TYGODNIA 't'
#define WEKTOR_LICZBY       'l'
// a tu nowy styl u?ywaj?cy klasy enum:
enum class TRodzajWypelnieniaWektora {
	rwwDniTygodnia, rwwLiczby
};
// define w nowym stylu:
constexpr auto MAX_ROZMIAR_LINII = 10;
constexpr auto ZNAK_FORMATUJACY = '*';
// typ wskaŸnika na funkcjê :
typedef string (*TFunkcjaFormatowanie)(const string&);
/*TODO: 
  czym ró¿ni siê ta definicja powy¿ej od :
  typedef string (TFunkcjaFormatowanie)(string);
  odpowiedŸ: to jest typ w zasadzie ma³o gdzie u¿ywany, 
  czêsto i tak jest konwertowany do string (*TFunkcjaFormatowanie)(string);
*/

