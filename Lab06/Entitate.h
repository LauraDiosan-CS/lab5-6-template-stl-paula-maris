#pragma once

#include <ostream>
using namespace std;

class Entitate {
private:
	int id;
	bool eliberata;
	char* nr;
	char* tip;
public:
	Entitate();
	Entitate(int id, const char* nr,const char* tip, bool eliberata);
	Entitate(const Entitate&);
	Entitate& operator=(const Entitate&);
	int getId();
	char* getTip();
	void setTip(char* tip);
	void setId(int id);
	char* getNr();
	void setNr(char* nr);
	void setEliberata(bool eliberata);
	bool getEliberata();
	bool operator==(const Entitate&);
	friend ostream& operator<<(ostream& os, const Entitate& s);
	void afisare();
	~Entitate();
};