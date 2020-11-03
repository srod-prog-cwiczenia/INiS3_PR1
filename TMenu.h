#pragma once
/*
  Zadanie: utworzyæ interfejs dla klasy TMenu.
  Uwaga: w C++ rolê interfejsów pe³ni¹ klasy abstrakcyjne (s¹ to
  klasy które nie mog¹ posiadaæ swoich instancji = obiektów).
*/
class TMenuAbs {
public:
	virtual unsigned int wybierz() = 0; /* wybieramy z menu */
	virtual void addAll(int ilePar, ...) = 0; /* @ilePar - ile opcji w menu 
											  (nie wliczaj¹æ opcji 0. Wyjscie)
											  dalej - otwarta lista parametrów */
};
//------------------------------------------------
class TMenu : public TMenuAbs
{
private:
	vector<string> tabItemsV;
	void add(string item);
public:
	void addAll(int ilePar, ...);
	unsigned int wybierz();
	TMenu();
	~TMenu();
};

