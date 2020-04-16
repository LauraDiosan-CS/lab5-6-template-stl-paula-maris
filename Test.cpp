#include "Test.h"
#include "Entitate.h"
#include "Service.h"
#include "RepoFile.h"
#include <assert.h>
#include "RepoTemplate.h"
#include <iostream>
#include <cassert>

using namespace std;

void test1()
{
	RezervareCamera t(1, "T17", "simpla", true);
	assert(strcmp(t.getTip(), "simpla") == 0);
	assert(t.getId() == 1);
	assert(t.getEliberata() == true);
	RezervareCamera t2(3, "P19", "dubla", false);
	assert(!(t == t2));
	t2 = t;
	assert(t2 == t);
}

void test2()
{
	RezervareCamera t3;
	assert(t3.getId() == 0);
	assert(t3.getEliberata() == true);
	assert(t3.getTip() == NULL);
	assert(t3.getNr() == NULL);
}

void test3()
{
	RezervareCamera t(1, "T17", "simpla", true);
	RezervareCamera t2(3, "P19", "dubla", false);
	assert(!(t == t2));
	t2 = t;
	assert(t2 == t);
}

void test4()
{
	RezervareCamera t(1, "A23", "simpla", true);
	RezervareCamera t1(2, "C2", "simpla", false);
	RezervareCamera t2(3, "P19", "dubla", false);
	RezervareCamera t3(4, "T17", "simpla", true);
	RepoTemplate<RezervareCamera> repo;
	repo.addElem(t);
	repo.addElem(t1);
	repo.addElem(t2);
	repo.addElem(t3);
	assert(repo.getSize() == 4);
	assert(repo.getAll()[0] == t);
	assert(repo.getAll()[1] == t1);
	assert(repo.getAll()[2] == t2);
	assert(repo.getAll()[3] == t3);
	assert(repo.findElem(t1) == true);
	repo.deleteElem(t3);
	assert(repo.getSize() == 3);
	assert(repo.findElem(t3) == false);
	assert(strcmp(t.getNr(), "A23") == 0);
	repo.updateElem(t2, RezervareCamera(3, "15C", "simpla", true));
	assert(strcmp(repo.getAll()[2].getTip(), "dubla") != 0);
	assert(strcmp(repo.getAll()[2].getTip(), "simpla") == 0);
}


void test6() {
	RepoFile<RezervareCamera> repo("Test1.txt");
	repo.clearFromFile();
	vector<RezervareCamera> list;
	repo.loadFromFile();
	list = repo.getAll();
	assert(repo.getSize() == 3);
	assert(list[0].getId() == 1);
	assert(list[1].getId() == 2);
	assert(strstr(list[1].getTip(), "simpla"));
	assert(list[2].getEliberata() == false);
}

void test7()
{
	RepoFile<RezervareCamera> r("Test2.txt");
	r.clearFromFile();
	assert(r.getSize() == 0);
	r.loadFromFile();	
	assert(r.getSize() == 3);
	vector<RezervareCamera> list;
	list = r.getAll();
	RezervareCamera e(4, "O1", "dubla", false);
	r.addElem(e);
	r.saveToFile();
	list = r.getAll();
	assert(r.getSize() == 4);
	r.deleteElem(e);
	assert(r.getSize() == 3);
	r.saveToFile();
	RezervareCamera new_e(5, "T17", "dubla", true);
	RezervareCamera e1 = r.getAll()[0];
	r.updateElem(e1, new_e);
	r.saveToFile();
	assert(strstr(r.getAll()[0].getTip(), "dubla"));
	RezervareCamera es(2, "T2", "dubla", true);
	assert(r.getAll()[1] == es);
	assert(r.findElemFromId(2) == es);
}

void test8()
{
	RepoFile<RezervareCamera> r("Test3.txt");		//repo
	Service s = { r };
	s.clearFromFile();								//service
	assert(s.getSize() == 0);
	s.loadFromFile();
	assert(s.getSize() == 3);
	vector<RezervareCamera> list;
	list = s.getAll();
	RezervareCamera e(4, "O1", "dubla", false);
	s.adauga(e);
	s.saveToFile();
	list = s.getAll();
	assert(s.getSize() == 4);
	s.deleteElem(e);
	assert(s.getSize() == 3);
	s.saveToFile();
	RezervareCamera new_e(5, "T17", "dubla", true);
	RezervareCamera e1 = s.getAll()[0];
	s.update(e1, new_e);
	s.saveToFile();
	assert(strstr(s.getAll()[0].getTip(), "dubla"));
	RezervareCamera es(2, "T2", "dubla", true);
	assert(s.getAll()[1] == es);
	assert(s.findElemFromId(2) == es);
}


void test9()
{
	RepoFile<RezervareCamera> r("Test4.txt");
	Service s = { r };
	s.clearFromFile();
	assert(s.getSize() == 0);						// 0 elemente in fisier
	s.loadFromFile();								//incarcarea elementelor din fisier
	assert(s.getSize() == 6);						// 6 elemente in fisier
	char tip[7];
	strcpy_s(tip, strlen("simpla") + 1, "simpla");			
	assert(s.procentaj(tip) == 100);				//apelarea functionalitatii din service
	char tip2[7];
	strcpy_s(tip2, strlen("dubla") + 1, "dubla");
	assert(s.procentaj(tip2) == 33);
	char tip3[7];
	strcpy_s(tip3, strlen("vip") + 1, "vip");
	assert(s.procentaj(tip3) == 0);
}