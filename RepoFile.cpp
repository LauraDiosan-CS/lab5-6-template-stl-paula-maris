#include "RepoFile.h"
#include <fstream>
#include <string>
using namespace std;


RepoFile::RepoFile(){
}

RepoFile::RepoFile(const char* fileName)
{
	fis = fileName;
	ifstream f(fileName);
	string linie;
	int id;
	char* tip = new char[10];
	char* nr = new char[10];
	bool eliberata;
	while (!f.eof()) {
		f >> id>>nr>>tip>>eliberata;
		if (nr != "" && tip!="") {
			RezervareCamera c(id,nr,tip,eliberata);
			elem.push_back(c);
		}
	}
	delete[] tip;
	delete[] nr;
	f.close();
}

void RepoFile::loadFromFile(const char* fileName)
{
	elem.clear();
	fis = fileName;
	ifstream f(fileName);
	int id;
	char* tip = new char[10];
	char* nr = new char[10];
	bool eliberata;
	while (!f.eof()) {
		f >> id >> nr >> tip >> eliberata;
		if (strcmp(nr, "") != 0 && strcmp(tip, "") != 0) {
			RezervareCamera c(id, nr, tip, eliberata);
			elem.push_back(c);
		}
	}
	delete[] tip;
	delete[] nr;
	f.close();
}

void RepoFile::addElem(RezervareCamera s)
{
	elem.push_back(s);
}

void RepoFile::updateElem(RezervareCamera s, int newId, char* newNr, char* newTip, bool newEliberata)
{
	vector<RezervareCamera>::iterator it;
	it = find(elem.begin(), elem.end(), s);
	if (it != elem.end()) {
		(*it).setId(newId);
		(*it).setTip(newTip);
		(*it).setNr(newNr);
		(*it).setEliberata(newEliberata);
	}

}

//returneaza pozitia la care se gaseste RezervareCameraul s, sau -1, daca acesta nu apare
int RepoFile::findElem(RezervareCamera s)
{
	vector<RezervareCamera>::iterator it;
	it = find(elem.begin(), elem.end(), s);
	if (it != elem.end()) {
		return distance(elem.begin(), it);
	}
	return -1;
}

//sterge elementul s din repository, returneaza 0 la succes, -1 altfel
int RepoFile::deleteElem(RezervareCamera s)
{
	vector<RezervareCamera>::iterator it;
	it = find(elem.begin(), elem.end(), s);
	if (it != elem.end()) {
		elem.erase(it);
		return 0;
	}
	return -1;
}

RezervareCamera RepoFile::findElemFromPos(int i)
{
	if (i < 0 or i >= elem.size())
		return RezervareCamera(0, "", "", false);
	return elem[i];
}

vector<RezervareCamera> RepoFile::getAll()
{
	return elem;
}

int RepoFile::size()
{
	return elem.size();
}

void RepoFile::saveToFile()
{
	ofstream f(fis);
	for (size_t i = 0; i < elem.size(); i++) {
		f << elem[i];
	}
	f.close();
}


RepoFile::~RepoFile(){
}