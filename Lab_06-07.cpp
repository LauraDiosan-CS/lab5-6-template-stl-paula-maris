// Lab_06-07.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Test.h"
#include "Entitate.h"
#include "RepoTemplate.h"
#include "UI.h"
#include "Service.h"
#include "ReposFile.h"
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
	int option;
	UI u;
	Service serv;
	ReposFile repo;
	repo.loadFromFile("Camere.txt");
	repo.clearFile("Camere.txt");
	serv.setRepo(repo);
	u.incarcaElemente(serv);								//daca dorim sa avem deja cateva elemente
	u.afisare(serv);
	bool stop = false;
	u.afisare_meniu();
	while (stop == false) {
		option = u.get_input();
		if (option == 1) {									//adaugarea unei camere
			u.addElem(serv);
			u.afisare(serv);
			u.afisare_meniu();
			continue;
		}
		if (option == 2) {									//stergerea unei camere
			u.deleteElem(serv);
			u.afisare(serv);
			u.afisare_meniu();
			continue;
		}
		if (option == 3) {									//actualizarea unei camere
			u.updateElem(serv);
			u.afisare(serv);
			u.afisare_meniu();
			continue;
		}
		if (option == 4) {
			u.afisare_procentaj(serv);						//afisarea procentajului tipurilor de camera
			u.afisare_meniu();
			continue;
		}
		if (option == 10) {
			u.afisare(serv);								//afisarea tuturor camerelor
			u.afisare_meniu();
			continue;	
		}
		if (option == 11) {
			stop = true;									//oprirea programului
			repo.getAll().clear();
		}
	}
	return 0;
}