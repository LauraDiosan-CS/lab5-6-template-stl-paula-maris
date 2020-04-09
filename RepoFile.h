#pragma once
#include "Entitate.h"
#include <vector>
using namespace std;

class RepoFile
{
private:
	vector<RezervareCamera> elem;
	const char* fis;
public:
	RepoFile();
	RepoFile(const char* fileName);
	void loadFromFile(const char* fileName);
	void addElem(RezervareCamera);
	void updateElem(RezervareCamera, int, char*, char*, bool);
	int findElem(RezervareCamera);
	int deleteElem(RezervareCamera);
	RezervareCamera findElemFromPos(int);
	vector<RezervareCamera> getAll();
	int size();
	void saveToFile();
	~RepoFile();
};