#pragma once
#include <string>
#include <vector>
#include <set>
#include <list>
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
// typ wska�nika na funkcj� :
typedef string (*TFunkcjaFormatowanie)(const string&);
/*TODO: 
  czym r�ni si� ta definicja powy�ej od :
  typedef string (TFunkcjaFormatowanie)(string);
  odpowied�: to jest typ w zasadzie ma�o gdzie u�ywany, 
  cz�sto i tak jest konwertowany do string (*TFunkcjaFormatowanie)(string);
*/

