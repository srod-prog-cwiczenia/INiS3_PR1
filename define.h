#pragma once
#include <string>
#include <vector>
#include <iostream>
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