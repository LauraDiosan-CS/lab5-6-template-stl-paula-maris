#pragma once

#include "Service.h"
#include "Entitate.h"
#include "Validator.h"
#include<iostream>
#include<vector>
#include<string>
using namespace std;


class UI {
private:
	Service serv;
	Validator valid;
	ReposFile repo;
public:
	void addElem(Service& serv);
	void deleteElem(Service& serv);
	void updateElem(Service& serv);
	void afisare(Service& serv);
	void afisare_procentaj(Service& serv);
	void afisare_meniu();
	void afisare_elib(Service& serv);
	int get_input();
	void incarcaElemente(Service& serv);
	void afisareFisier(Service& serv);
};