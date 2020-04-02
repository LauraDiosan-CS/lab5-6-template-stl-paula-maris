#pragma once

#include <iostream>
using namespace std;

template <class T, int CAP = 10>
class Vector {
private:
	T elem[CAP];
	int size;
public:
	Vector();
	Vector(const Vector<T, CAP>& v);
	~Vector();
	void addElem(T el);
	void deleteElem(int pos);
	void updateElem(T el, int pos);
	int getSize();
};

//In: -
//Out:tip vector fara elemente
template <class T, int CAP> Vector<T, CAP>::Vector() {
	this->size = 0;
}

//Constructor de copiere
//In:alt vector
//Out:instanta unui vector
template <class T, int CAP> Vector<T, CAP>::Vector(const Vector<T, CAP>& v) {
	//TO DO
	this->size = v.size;
	for (int i = 0; i < v.size; i++) {
		this->elem[i] = v.elem[i];
	}
}
//Destructor
//In:un vector
//Out:-
template <class T, int CAP> Vector<T, CAP>::~Vector() {
	//TO DO
	this->size = 0;
}
//Adaugarea unui element
//In:Vectorul si elementul
//Out:Vectorul modificat
template <class T, int CAP> void Vector<T, CAP>::addElem(T e) {
	if (this->size < CAP)
		this->elem[this->size++] = e;
	else
		cout << "not enogh space..." << endl;
}
//Stergerea unui element
//In:Vectorul si pozitia
//Out:Vectorul fara elementul sters
template <class T, int CAP> void Vector<T, CAP>::deleteElem(int pos) {
	this->elem[pos] = this->elem[--this->size];
}


//Actualizarea unui element
//In: Vectorul si pozitia
//Out: Vectorul cu elementul modificat
template <class T, int CAP> void Vector<T, CAP>::updateElem(T e,int pos) {
	this->elem[pos] = e;
}


//Acceseaza numarul de elemente din vector
//In:vectorul
//Out:dimensiunea vectorului
template <class T, int CAP> int Vector<T, CAP>::getSize() {
	return this->size;
}

