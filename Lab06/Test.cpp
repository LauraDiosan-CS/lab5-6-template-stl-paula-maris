#include "Test.h"
#include "Entitate.h"
#include <assert.h>
#include "Repository.h"
#include <iostream>
#include <cassert>
using namespace std;


void test1() {
	Entitate t1 = Entitate();
	assert(t1.getNr() == 0);
	assert(t1.getTip() == NULL);
	assert(t1.getNr() == NULL);
	assert(t1.getEliberata() == true);
}

void test2() {
	Entitate t2 = Entitate(1,"A23", "dubla",true);
	assert(t2.getId() == 1);
	assert(t2.getEliberata() == true);
}


void test3()
{
	Entitate t = Entitate(1, "A23", "simpla", true);
	Entitate t1 = Entitate(2, "A19", "dubla", false);
	Entitate t2 = Entitate(3, "B5", "simpla", true);
	RepositorySTL elem;
	elem.addElem(t);
	elem.addElem(t1);
	elem.addElem(t2);
	assert(elem.getSize() == 3);
}

void test4()
{
	Entitate t = Entitate(1, "A23", "simpla", true);
	Entitate t1 = Entitate(2, "A19", "dubla", false);
	Entitate t2 = Entitate(3, "B5", "simpla", true);
	RepositorySTL elem;
	elem.addElem(t);
	elem.addElem(t1);
	elem.addElem(t2);
	assert(elem.getSize() == 3);
	elem.deleteElem(t2);
	assert(elem.getSize() != 3);
}

void test5()
{
	Entitate t = Entitate(1, "A23", "simpla", true);
	Entitate t1 = Entitate(2, "A19", "dubla", false);
	Entitate t2 = Entitate(3, "B5", "simpla", true);
	Entitate t3 = Entitate(4, "T17", "complexa", false);
	RepositorySTL elem;
	elem.addElem(t);
	elem.addElem(t1);
	elem.addElem(t2);
	assert(elem.getSize() == 3);
	elem.deleteElem(t2);
	elem.deleteElem(t);
	assert(elem.getSize() == 1);
	elem.addElem(t3);
	assert(elem.getSize() != 3);
}