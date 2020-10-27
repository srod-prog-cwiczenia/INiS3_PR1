#include "FormatowanieKolekcji.h"
FormatowanieKolekcji::FormatowanieKolekcji(const int ile) :
  TestKolekcji(ile) {};
string FormatowanieKolekcji::formatowanie(const string &linia) {

  //zadanie napisaæ krótkie ,,centrowanie'' 
  //lancucha linia, to znaczy _____1_____
   if (linia.length() >=  MAX_ROZMIAR_LINII) 
     return linia;
   unsigned int ile = 
     (MAX_ROZMIAR_LINII - linia.length()) / 2; 
   return string(ile, ZNAK_FORMATUJACY) + linia + 
       string(ile, ZNAK_FORMATUJACY);
};  