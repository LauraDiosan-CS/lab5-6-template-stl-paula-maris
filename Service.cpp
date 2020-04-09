#include "Service.h"
#include <iostream>

using namespace std;


//constructor implicit
Service::Service() {
}

void Service::setRepo(const ReposFile& r)
{
	reposFile = r;
}

//destructor
Service::~Service() {
}

//constructor cu paramentru
Service::Service(const ReposFile& r)
{
	reposFile = r;
}

//citeste elementele din fisier
void Service::loadFromFile(const char* fileName)
{
	this->reposFile.loadFromFile(fileName);
}

//sterge elementele din fisier
void Service::clearFile(const char* fileName)
{
	this->reposFile.clearFile(fileName);
}

//scrie un element in fisier text
void Service::saveToFile()
{
	this->reposFile.saveToFile();
}

//returneaza toate elementele din reposFile
void Service::getAllFile()
{
	reposFile.getAllFile();
}

//adauga un element (apeleaza addElem din reposFile)
//in: element de tip RezervareCamera
//out: -
void Service::adauga(RezervareCamera&e)
{
	//repoTemplate.addElem(e);
	reposFile.addElem(e);
	reposFile.saveToFile();
}

//sterge un element
//in: element de tip RezervareCamera
//out -
void Service::deleteElem(RezervareCamera& e) {
	//repoTemplate.deleteElem(e);
	reposFile.deleteElem(e);
	reposFile.saveToFile();
}

//actualizarea unui element
//in: element de tip RezervareCamera
//out: -
void Service::update(RezervareCamera& e, RezervareCamera& new_e) {
	//repoTemplate.updateElem(e, new_e);
	reposFile.updateElem(e, new_e);
	reposFile.saveToFile();
}


//returneaza toate elementele(apeleaza get all din repo)
vector<RezervareCamera> Service::getAll()
{
	//return this->repoTemplate.getAll();
	return reposFile.getAll();
}

//gaseste elementul cu un id dat
RezervareCamera Service::findElemFromId(int id) 
{
	//return repoTemplate.findElemFromId(id);
	return reposFile.findElemFromId(id);
}

//dimensiunea service-ului
int Service::getSize()
{
	//return repoTemplate.getSize();
	return reposFile.getSize();
}

void Service::procentaj(ReposFile reposFile, int v[3]) {
	reposFile.loadFromFile("Camere.txt");
	vector<RezervareCamera> elem = reposFile.getAll();

	int contor_dubla = 0;
	int dubla_true = 0;
	int contor_vip = 0;
	int vip_true = 0;
	int contor_simpla = 0;
	int simpla_true = 0;
	for (int i = 0; i < elem.size(); i++)
	{
		if (strstr(elem[i].getTip(), "simpla"))
		{
			contor_simpla++;
			if (elem[i].getEliberata() == true)
				simpla_true++;
		}
		if (strstr(elem[i].getTip(), "vip"))
		{
			contor_vip++;
			if (elem[i].getEliberata() == true)
				vip_true++;
		}
		if (strstr(elem[i].getTip(), "dubla"))
		{
			contor_dubla++;
			if (elem[i].getEliberata() == true)
				dubla_true++;
		}
	}
	float procentaj_simpla = 0.0;
	float procentaj_dubla = 0.0;
	float procentaj_vip = 0.0;
	cout << contor_simpla;
	procentaj_simpla = (100 * simpla_true) / contor_simpla;
	procentaj_dubla = (100 * dubla_true) / contor_dubla;
	procentaj_vip = (100 * vip_true) / contor_vip;
	int x[3];
	x[2] = procentaj_simpla;
	x[0] = procentaj_dubla;
	x[1] = procentaj_vip;
	int aux = 0;
	for (int i = 0; i < 2; i++)
		for (int j = i + 1; j < 3; j++)
			if (x[i] >= x[j])
			{
				aux = x[i];
				x[i] = x[j];
				x[j] = aux;
			}

	//1 pentru simpla
	//2 pentru dubla
	//3 pentru vip

	int k1 = 0;
	int k2 = 0;
	int k3 = 0;
	for (int i = 0; i < 3; i++)
	{
		if (x[i] == procentaj_simpla && k1 == 0)
		{
			k1++;
			v[i] = procentaj_simpla * 10 + 1;
			
		}
		if (x[i] == procentaj_dubla && k2 == 0)
		{
			k2++;
			v[i] = procentaj_dubla * 10 + 2;
		}
		if (x[i] == procentaj_vip && k3 == 0)
		{
			k3++;
			v[i] = procentaj_vip * 10 + 3;
		}
	}
	
}
