#include "ReposFile.h"

//constructor implicit
ReposFile::ReposFile() {
}

//destructor
ReposFile::~ReposFile(){
}

//constructor cu param
ReposFile::ReposFile(const char* fileName)
{
	int id = 0;
	bool eliberata = true;
	char* nr = new char[10];
	char* tip = new char[10];
	fis = fileName;
	ifstream f(fileName);
	string linie;
	while (!f.eof()) {
		f >> id >> nr >> tip >> eliberata;
		RezervareCamera e(id, nr, tip, eliberata);
		rep.addElem(e);
	}
	delete[] nr;
	delete[] tip;
	f.close();
}

//stergerea elementelor din fisier
void ReposFile::clearFile(const char* fileName)
{
	int id = 0;
	bool eliberata = true;
	char* nr = new char[10];
	char* tip = new char[10];
	fis = fileName;
	ifstream f(fileName);
	while (!f.eof()) {
		f >> id >> nr >> tip >> eliberata;
		RezervareCamera e(id, nr, tip, eliberata);
		rep.deleteElem(e);
	}
	delete[] nr;
	delete[] tip;
	f.close();
}

//citirea datelor din fisier
void ReposFile::loadFromFile(const char* fileName)
{
	rep.getAll().clear();
	int id = 0;
	bool eliberata = true;
	char* nr = new char[10];
	char* tip= new char[10];
	fis = fileName;
	ifstream f(fileName);
	while (!f.eof()) {
		f >> id >> nr >> tip >> eliberata;
		RezervareCamera e(id, nr, tip, eliberata);
		rep.addElem(e);
	}
	delete[] nr;
	delete[] tip;
	f.close();
}

//adaugarea unui element
void ReposFile::addElem(RezervareCamera& a)
{
	rep.addElem(a);
}

//stergerea unui element
void ReposFile::deleteElem(RezervareCamera& a)
{
	rep.deleteElem(a);
}

//actualizarea unui element
void ReposFile::updateElem(RezervareCamera& a,RezervareCamera& new_a)
{
	rep.updateElem(a, new_a);
}

//gasirea unui element dupa id
RezervareCamera ReposFile::findElemFromId(int id)
{
	return rep.findElemFromId(id);
}

//returnarea tuturor elementelor
vector<RezervareCamera> ReposFile::getAll()
{
	return rep.getAll();
}

//dimensiunea din repo
int ReposFile::getSize()
{
	return rep.getAll().size();
}

//salvarea datelor in fisier
void ReposFile::saveToFile()
{
	ofstream f(fis);
	for (size_t i = 0; i < rep.getAll().size(); i++) {
		if (i!= rep.getAll().size()-1)
			f << rep.getAll()[i].getId() << " " << rep.getAll()[i].getNr() << " " << rep.getAll()[i].getTip() << " " << rep.getAll()[i].getEliberata()<<endl;
		else
			f << rep.getAll()[i].getId() << " " << rep.getAll()[i].getNr() << " " << rep.getAll()[i].getTip() << " " << rep.getAll()[i].getEliberata();
	}
	f.close();
}

vector<RezervareCamera> ReposFile::getAllFile()  
{
	return this->getAll();
}