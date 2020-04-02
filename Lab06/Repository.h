#pragma once
#include "Entitate.h" 
#include <vector>

using namespace std;


class RepositorySTL
{
private:
	vector<Entitate> elem;

public:
	RepositorySTL();
	RepositorySTL(const RepositorySTL& r);
	~RepositorySTL();
	void addElem(Entitate);
	vector<Entitate>deleteElem(Entitate);
	void update(Entitate);
	int getSize();
	vector<Entitate> getAll();
};