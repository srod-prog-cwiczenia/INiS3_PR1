#pragma once
/*
  Zadanie: utworzy� interfejs dla klasy TMenu.
  Uwaga: w C++ rol� interfejs�w pe�ni� klasy abstrakcyjne (s� to
  klasy kt�re nie mog� posiada� swoich instancji = obiekt�w).
*/
class TMenuAbs {
public:
	virtual unsigned int wybierz() = 0; /* wybieramy z menu */
	virtual void addAll(int ilePar, ...) = 0; /* @ilePar - ile opcji w menu 
											  (nie wliczaj�� opcji 0. Wyjscie)
											  dalej - otwarta lista parametr�w */
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

