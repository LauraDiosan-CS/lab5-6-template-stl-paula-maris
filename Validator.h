#pragma once
#include "Entitate.h"
#include "ReposFile.h"
#include <vector>
using std::vector;

using namespace std;

class Validator {
private:
	ReposFile reposFile;
public:
	Validator();
	Validator(const ReposFile& r);
	bool id_unic(int id);
	//bool eliberata(bool eliberata);
	~Validator();

};
