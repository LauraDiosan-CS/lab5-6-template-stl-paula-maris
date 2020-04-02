#include "Repository.h"
#include <iostream>

using namespace std;


//constructor fara param
RepositorySTL::RepositorySTL() {
	this->elem;
}

//constuctor de copiere
RepositorySTL::RepositorySTL(const RepositorySTL& r) {
	this->elem = r.elem;
}


//adaugarea unui element
//in: elementul de adaugat
//out: -
void RepositorySTL::addElem(Entitate s) {
	elem.push_back(s);
}


//eliminare element
//in: -
//out: noul repo cu elementul sters
vector<Entitate> RepositorySTL::deleteElem(Entitate s) {
	for (int i = 0; i < elem.size(); i++) {
		if (elem[i] == s) {
			int pos = i;
			elem.erase(elem.begin() + pos);
		}
	}
	return elem;
}


//actualizarea unui element cu date de la tastatura
//in: elementul de actualizat
//out: noul repo cu elementul actualizat
void RepositorySTL::update(Entitate s) {
	for (int i = 0; i < elem.size(); i++)
		if (elem[i] == s)
		{
			cout << "Introduceti modificarile: " << endl;
			int id;
			char nr[10];
			bool eliberata;
			char tip[10];
			cout << "Dati id-ul:";
			cin >> id;
			cout << "Dati numarul: ";
			cin >> nr;
			cout << "Dati tipul: ";
			cin >> tip; 
			cout << "Dati statusul (true/false): ";
			cin >> eliberata;
			elem[i].setId(id);
			elem[i].setNr(nr);
			elem[i].setTip(tip);
			elem[i].setEliberata(eliberata);
			return;
		}
}


//dimensiunea vectorului
//in: -
//out: dimensiunea repository-ului (int)
int RepositorySTL::getSize() {
	return elem.size();
}


//returnarea tuturor elementelor
//in: -
//out: un vector de entitati
vector<Entitate> RepositorySTL::getAll() {
	return elem;
}


//destructorul
RepositorySTL::~RepositorySTL()
{}