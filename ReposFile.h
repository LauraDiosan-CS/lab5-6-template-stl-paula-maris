#pragma once

#include <fstream>
#include <ostream>
#include <vector>
#include <list>
#include <string>
#include "RepoTemplate.h"
#include "Entitate.h"

using namespace std;

class ReposFile :public RepoTemplate<RezervareCamera> {
private:
	const char* fis;
public:
	RepoTemplate rep;
	void loadFromFile(const char* fileName);
	void saveToFile();
	ReposFile(const char* fileName);
	ReposFile();
	~ReposFile();
	void addElem(RezervareCamera&);
	void clearFile(const char* fileName);
	void deleteElem(RezervareCamera&);
	RezervareCamera findElemFromId(int id);
	void updateElem(RezervareCamera&,RezervareCamera&);
	int getSize();
	vector<RezervareCamera> getAll();
	vector<RezervareCamera> getAllFile();
};