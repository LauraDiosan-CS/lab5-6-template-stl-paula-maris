#pragma once

#include "RepoTemplate.h"
#include <vector>
#include "Entitate.h"
#include "ReposFile.h"
using std::vector;

using namespace std;

class Service {
private:
	//RepoSTLTemplate<class T> repoTemplate;
	//RepoTemplate<class T> repoTemplate;
	RepoTemplate<RezervareCamera> repoTemplate;
	ReposFile reposFile;
public:
	Service();
	void setRepo(const ReposFile& r);
	void clearFile(const char* fileName);
	Service(const ReposFile& r);
	//Service(const RepoTemplate<RezervareCamera>&);
	void adauga(RezervareCamera& e);
	void deleteElem(RezervareCamera& e);
	void update(RezervareCamera& e, RezervareCamera& new_e);
	void incarcaElemente();
	int getSize();
	RezervareCamera findElemFromId(int id);
	void procentaj(ReposFile r, int v[3]);
	vector<RezervareCamera> getAll();  // era vector in loc de list	
	void loadFromFile(const char* fileName);
	void saveToFile();
	//void readFromFile(string filename, int& nrlines);
	//void writeInFile(string filename, RezervareCamera& e);  //era T
	//list<T> getAllFile();
	void getAllFile();
	~Service();

	/*void return_rest(int pretClient, int codProdus);
	int selectare_produs2(int codProdus);*/
};