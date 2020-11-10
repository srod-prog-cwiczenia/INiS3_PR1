#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <cstdarg>
#include <assert.h>
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
typedef string (*TFunkcjaFormatowanie)(string);
/*TODO: 
  czym ró¿ni siê ta definicja powy¿ej od :
  typedef string (TFunkcjaFormatowanie)(string);
*/

