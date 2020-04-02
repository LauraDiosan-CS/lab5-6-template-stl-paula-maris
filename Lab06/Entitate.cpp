#include "Entitate.h"
#include <string.h>
#include <iostream>
#include <istream>
#include <cstddef>
#include <ostream>

using namespace std;

//constructor default(fara param)
Entitate::Entitate() {
	this->tip = NULL;
	this->nr = NULL;
	this->id = 0;
	this->eliberata = true;
}

//constructor cu param
Entitate::Entitate(int id, const char* nr, const char* tip, bool eliberata) {
	this->tip = new char[strlen(tip) + 1];
	strcpy_s(this->tip, strlen(tip) + 1, tip);
	this->nr = new char[strlen(nr) + 1];
	strcpy_s(this->nr, strlen(nr) + 1, nr);
	this->id = id;
	this->eliberata = eliberata;
}

//constructor de copiere
Entitate::Entitate(const Entitate& s) {
	this->tip = new char[strlen(s.tip) + 1];
	strcpy_s(this->tip, strlen(s.tip) + 1, s.tip);
	this->nr = new char[strlen(s.nr) + 1];
	strcpy_s(this->nr, strlen(s.nr) + 1, s.nr);
	this->eliberata = s.eliberata;
	this->id = s.id;
}

//getter pentru id
int Entitate::getId() {
	return this->id;
}

//setter pentru id
void Entitate::setId(int c) {
	this->id = c;
}

//getter pentru pret
bool Entitate::getEliberata() {
	return this->eliberata;
}

//setter pentru pret
void Entitate::setEliberata(bool eliberata) {
	this->eliberata = eliberata;
}

//getter pentru tip
char* Entitate::getTip() {
	return this->tip;
}

//setter pentru tip
void Entitate::setTip(char* t) {
	if (tip) delete[]tip;
	tip = new char[strlen(t) + 1];
	strcpy_s(tip, strlen(t) + 1, t);
}

//getter pentru nr
char* Entitate::getNr() {
	return this->nr;
}

//setter pentru nr
void Entitate::setNr(char* t) {
	if (nr) delete[]nr;
	nr = new char[strlen(t) + 1];
	strcpy_s(nr, strlen(t) + 1, t);
}

//destructor
Entitate::~Entitate() {
	if (tip) delete[]tip;
	tip = NULL;
	if (nr) delete[]nr;
	nr = NULL;
	id = -1;
	eliberata = true;
}

//suprascrie operatorul "=" pentru un element de tip entitate
Entitate& Entitate::operator=(const Entitate& s) {
	this->setId(s.id);
	this->setEliberata(s.eliberata);
	this->setTip(s.tip);
	this->setNr(s.nr);
	return *this;
}

//operatorul de egalitate
bool Entitate::operator==(const Entitate& s) {
	return (id == s.id) && eliberata == s.eliberata && (strcmp(tip, s.tip) == 0 && (strcmp(nr, s.nr) == 0));
}

//afisarea1
ostream& operator<<(ostream& os, const Entitate& s)
{
	os << "id-ul: " << s.id << ", numarul: " << s.nr<< ", tipul: " << s.tip << ", eliberata: " << s.eliberata << endl;
	return os;
}

//afisare2
void Entitate::afisare() {
	cout << "id: " << this->id << ", numarul: " << this->nr << ", tip: " << this->tip<< ", eliberata: " << this->eliberata;

}