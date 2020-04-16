#pragma once
#include <vector>
#include "Entitate.h"
#include <list>
#include <algorithm>
using namespace std;

template <class T> class RepoTemplate
{
protected:
	vector<T> elem;
public:
	RepoTemplate<T>() {}
	RepoTemplate(const char* fileName);
	void deleteElem(const T&);
	void addElem(const T&);
	T findElemFromId(int id);
	bool findElem(const T&);
	int getSize();
	void updateElem(const T& s, const T& nou);
	vector<T> getAll();
	T getElement(int poz)  
	{
		return this->elem[poz];
	}
	void clear() {   
		this->elem.clear();
	}
	~RepoTemplate();
};


//Adaugarea unui element
//in: un obiect de tip T
//out: -
template<class T>
void RepoTemplate<T>::addElem(const T& e)
{
	elem.push_back(e);
}

//Stergerea unui element
//in: un obiect de tip T
//out: -
template<class T>
void RepoTemplate<T>::deleteElem(const T& e)
{
	for (int i = 0; i < elem.size(); i++) {
		if (elem[i] == e) {
			int pos = i;
			elem.erase(elem.begin() + pos);
		}
	}
}

//Aflarea unui element in repo
//in: un obiect de tip T
//out: true daca acesta se afla in repo, false altfel
template<class T>
bool RepoTemplate<T>::findElem(const T& e)
{
	int pos = 0;
	for (T crt : elem) {
		pos++;
		if (crt == e) 
			return true;
	}
	return false;
}

//Returnarea dimensiunii repo-ului
//in: -
//out: dimensiunea repo-ului
template<class T>
int RepoTemplate<T>::getSize()
{
	return elem.size();
}

//Aflarea elementului dupa id
//in: id, int
//out: un element de tip RezervareCamera
template<class T>
T RepoTemplate<T>::findElemFromId(int id)
{
	for (int i = 0; i < elem.size(); i++) {
		if (elem[i].getId() == id)
			return elem[i];
	}
	return RezervareCamera(0, "", "", false);
}

//Actualizarea unei camere
//in: vechi, nou: 2 obiecte de tip T
//out: repo-ul cu elementul actualizat
template<class T>
void RepoTemplate<T>::updateElem(const T& vechi, const T& nou)
{
	replace(elem.begin(), elem.end(), vechi, nou);
}

//getALL()
//in: -
//out: toate elementele de tip  T
template<class T>
vector<T> RepoTemplate<T>::getAll()
{
	return elem;
}

//destructorul
template <class T> RepoTemplate<T>::~RepoTemplate() {
}
