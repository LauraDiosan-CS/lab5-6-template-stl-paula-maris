#include "Validator.h"
#include <iostream>

using namespace std;

//constructor implicit
Validator::Validator() {
}

//destructor
Validator::~Validator() {
}

//construcor cu paramentru
Validator::Validator(const ReposFile& r)
{
	reposFile = r;
}
bool Validator::id_unic(int id)
{
	vector<RezervareCamera> elem = reposFile.getAll();
	for (int i = 0; i < elem.size(); i++)
	{
		if (elem[i].getId() == id)
			return false;
	}
	return true;
}