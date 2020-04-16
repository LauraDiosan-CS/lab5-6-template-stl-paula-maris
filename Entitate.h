#pragma once

#include <ostream>
using namespace std;

class RezervareCamera {
private:
	int id;
	bool eliberata;
	char* nr;
	char* tip;
public:
	RezervareCamera();
	RezervareCamera(int id, const char* nr, const char* tip, bool eliberata);
	RezervareCamera(const RezervareCamera&);
	RezervareCamera& operator=(const RezervareCamera&);
	int getId();
	char* getTip();
	void setTip(char* tip);
	void setId(int id);
	char* getNr();
	void setNr(char* nr);
	void setEliberata(bool eliberata);
	bool getEliberata();
	bool operator==(const RezervareCamera&);
	//RezervareCamera& operator=(const RezervareCamera& p);
	//bool operator==(const RezervareCamera& p);
	friend ostream& operator<<(ostream& os, const RezervareCamera& p);
	friend istream& operator>>(istream& is, RezervareCamera& p); 
	void afisare();
	~RezervareCamera();
};