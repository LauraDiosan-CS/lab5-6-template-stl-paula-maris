#include "Service.h"
#include <iostream>

using namespace std;


//constructor implicit
Service::Service() {
}

//destructor
Service::~Service() {
}

//constructor cu paramentru pentru RepoTemplate
Service::Service(const RepoTemplate<RezervareCamera>& repository) : repo{ repository } {}

//constructor cu paramentru pentru RepoFile
Service::Service(const RepoFile<RezervareCamera>& repository) : reposFile{ repository } {}


//citeste elementele din fisier
void Service::loadFromFile() 
{
	reposFile.loadFromFile();
	reposFile.saveToFile();
}

//sterge elementele din fisier
void Service::clearFromFile()
{
	reposFile.clearFromFile();
}


//scrie un element in fisier text
void Service::saveToFile()
{
	reposFile.saveToFile();
}


//adauga un element (apeleaza addElem din reposFile)
//in: element de tip RezervareCamera
//out: -
void Service::adauga(RezervareCamera& e)
{
	reposFile.addElem(e);
	reposFile.saveToFile();
}

//sterge un element
//in: element de tip RezervareCamera
//out -
void Service::deleteElem(RezervareCamera& e) {
	reposFile.deleteElem(e);
	reposFile.saveToFile();
}

//actualizarea unui element
//in: element de tip RezervareCamera
//out: -
void Service::update(RezervareCamera& e, RezervareCamera& new_e) {
	reposFile.updateElem(e, new_e);
	reposFile.saveToFile();
}


//returneaza toate elementele(apeleaza get all din repo)
vector<RezervareCamera> Service::getAll()
{
	
	return reposFile.getAll();
}

//gaseste elementul cu un id dat
RezervareCamera Service::findElemFromId(int id) 
{
	
	return reposFile.findElemFromId(id);
}

//dimensiunea service-ului
int Service::getSize()
{
	return reposFile.getSize();
}

//determinarea procentajului unui anumit tip
//in: tip, char
//out: procent, int
int Service::procentaj(char* tip)
{
	vector<RezervareCamera> elem = reposFile.getAll();

	int nrCam = 0;
	int nrCamEliberate = 0;

	for (int i = 0; i < elem.size(); i++)
	{
		if (strcmp(elem[i].getTip(),tip) == 0)
		{
			nrCam++;
			if (elem[i].getEliberata() == true)
				nrCamEliberate++;
		}
	}

	int procent = (nrCamEliberate*100)/nrCam;

	return procent;
}

//determinarea tipurilor si sortarea dupa procentaj
void Service::procentaj_tipuri()
{
	vector<RezervareCamera> elem = reposFile.getAll();

	char tipuri[100][10]; int k = -1;
	for (int i = 0; i < elem.size(); i++)
		strcpy_s(tipuri[i], strlen("") + 1, "");					//vector nul
	for (int i = 0; i < elem.size(); i++)
	{
		int ok = 0;
		for (int k = 0; k < elem.size(); k++)
			if (strcmp(elem[i].getTip(), tipuri[k]) == 0)
				ok++;
		if (ok == 0)
		{
			k++;
			strcpy_s(tipuri[k], strlen(elem[i].getTip()) + 1, elem[i].getTip());
		}
	}
	char aux[10];
	for (int i=0;i<=k-1;i++)
		for (int j=i+1;j<=k;j++)
				if (procentaj(tipuri[i]) >= procentaj(tipuri[j]))
				{
					strcpy_s(aux, strlen(tipuri[i]) + 1, tipuri[i]); 
					strcpy_s(tipuri[i], strlen(tipuri[j]) + 1, tipuri[j]);
					strcpy_s(tipuri[j], strlen(aux) + 1, aux);
				}
	for (int i=0;i<=k;i++)
		if (!(strcmp(tipuri[i], "") == 0))
			cout << tipuri[i] << ": " << procentaj(tipuri[i]) << "%;" << endl;
}
