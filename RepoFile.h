#pragma once
#include"RepoTemplate.h"
#include <fstream>
#include <iostream>
#include <cstddef>


template <class T>
class RepoFile : public RepoTemplate<T>
{
private:
	char* filename;
public:
	RepoFile() : RepoTemplate<T>()
	{
		this->filename = NULL;
	};
	RepoFile(const char* fileName);
	RepoFile(const RepoFile& repo);
	void deleteElem(const T&);
	void addElem(const T&);
	int getSize();
	void updateElem(const T& s, const T& nou);
	void loadFromFile();
	void saveToFile();
	void setFilename(const char* filename);
	void clearFromFile();
	RepoFile<T>& operator=(const RepoFile<T>& repo);
	~RepoFile();
};


template<class T> RepoFile<T>::~RepoFile()
{
	delete[] this->filename;
}

template<class T> RepoFile<T>::RepoFile(const RepoFile& repo)
{
	this->filename = new char[strlen(repo.filename) + 1];
	strcpy_s(this->filename, strlen(repo.filename) + 1, repo.filename);
	this->loadFromFile();
}

template<class T>int RepoFile<T>::getSize()
{
	return RepoTemplate<T>::getSize();
}
	
template<class T> void RepoFile<T>::addElem(const T& e) {
	RepoTemplate<T>::addElem(e);
}

template<class T> void RepoFile<T>::deleteElem(const T& e) {
	RepoTemplate<T>::deleteElem(e);
};

template<class T> void RepoFile<T>::updateElem(const T &e, const T &new_e) {
	RepoTemplate<T>::updateElem(e, new_e);
}

template<class T> void RepoFile<T>::clearFromFile() {
	RepoTemplate<T>::clear();
}

template<class T> void RepoFile<T>::setFilename(const char* filename)
{
	if (this->filename != NULL) {
		delete[] this->filename;
	}
	if (filename != NULL) {
		this->filename = new char[strlen(filename) + 1];
		strcpy_s(this->filename, strlen(filename) + 1, filename);
	}
	else
		this->filename = NULL;
}
	
template<class T> void RepoFile<T>::loadFromFile()
{
	if (this->filename != NULL)
	{
		ifstream f(this->filename);
		T elem;

		while (f>>elem)
		{
			RepoTemplate<T>::addElem(elem);
			saveToFile();
		}
		f.close();
	}
	else
		RepoTemplate<T>::clear();
}

template<class T> void RepoFile<T>::saveToFile()
{
	if (this->filename != NULL) {
		ofstream f(this->filename);
		int n = RepoTemplate<T>::getSize();
		for (size_t i = 0; i < n; i++) {
			if (i != n - 1)
				f << RepoTemplate<T>::getElement(i).getId() << " " << RepoTemplate<T>::getElement(i).getNr() << " " << RepoTemplate<T>::getElement(i).getTip() << " " << RepoTemplate<T>::getElement(i).getEliberata() << endl;
			else
				f << RepoTemplate<T>::getElement(i).getId() << " " << RepoTemplate<T>::getElement(i).getNr() << " " << RepoTemplate<T>::getElement(i).getTip() << " " << RepoTemplate<T>::getElement(i).getEliberata();
		}
		f.close();
	}
}

template<class T> RepoFile<T>::RepoFile(const char* filename)
{
	this->filename = new char[strlen(filename) + 1];
	strcpy_s(this->filename, strlen(filename) + 1, filename);
	this->loadFromFile();
}

template<class T> RepoFile<T>& RepoFile<T>::operator=(const RepoFile<T>& repo)
{
	this->setFilename(repo.filename);
	this->loadFromFile();
	return *this;
}
