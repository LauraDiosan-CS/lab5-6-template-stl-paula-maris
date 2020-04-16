#pragma once

#include "Service.h"
#include "Entitate.h"
#include<iostream>
#include<vector>
#include<string>
using namespace std;


class UI {
private:
	Service serv;
public:
	UI();
	UI(const Service& service);
	~UI();
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
	void run_ui(Service& serv);
};