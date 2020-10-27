#pragma once
class TMenu
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

