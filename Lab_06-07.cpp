// Lab_06-07.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Test.h"
#include "Entitate.h"
#include "RepoTemplate.h"
#include "UI.h"
#include "Service.h"
#include "RepoFile.h"
#include <iostream>
#include <string.h>
#include <string>

using namespace std;


int main() {
	cout << "start tests..." << endl;
	test1();
	test2();
	test3();
	test4();
	test6();
	test7();
	test8();
	test9();
	cout << "succes" << endl;

							/* ------ RepoFile ------*/
	RepoFile<RezervareCamera> repoFile("Camere.txt"); Service service = { repoFile };

						  /* ------ RepoTemplate ------*/
	//RepoTemplate<RezervareCamera> repo; Service service = { repo };

	UI u = { service };
	u.run_ui(service);
	return 0;
}