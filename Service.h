#pragma once

#include "RepoTemplate.h"
#include <vector>
#include "Entitate.h"
#include "RepoFile.h"
using std::vector;

using namespace std;

class Service {
private:
	RepoTemplate<RezervareCamera> repo;
	RepoFile<RezervareCamera> reposFile;
public:
	Service();
	Service(const RepoTemplate<RezervareCamera>& repository);
	Service(const RepoFile<RezervareCamera>& repository);
	void adauga(RezervareCamera& e);
	void deleteElem(RezervareCamera& e);
	void update(RezervareCamera& e, RezervareCamera& new_e);
	int getSize();
	void clearFromFile();
	RezervareCamera findElemFromId(int id);
	int procentaj(char* tip);
	void procentaj_tipuri();
	vector<RezervareCamera> getAll();  
	void loadFromFile();
	void saveToFile();
	~Service();
};