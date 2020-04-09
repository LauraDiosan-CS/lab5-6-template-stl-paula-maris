#include "UI.h"
#include<iostream>
using namespace std;

//partea de interfata cu utilizatorul pt a adauga o camera
void UI::addElem(Service& serv)
{
	int id = 0;
	char* tip =new char[10];
	char* nr=new char[10];
	bool eliberata=true;
	int k = 0;
	while (k == 0)
	{
		cout << "Introduceti id-ul camerei: ";
		cin >> id;
		if (valid.id_unic(id) == true)
			k = 1;
		else
			cout << "Id-ul trebuie sa fie unic! " << endl;
	}
	cout << "Introduceti numarul camerei: ";
	cin >> nr;
	cout << "Introduceti tipul camerei: ";
	cin >> tip;
	cout << "Introduceti statusul camerei (1/0): ";
	cin >> eliberata;
	RezervareCamera e(id,nr,tip,eliberata);
	serv.adauga(e);
	cout << "Camera adaugata cu succes!" << endl << endl;
}

//stergerea unei camere
void UI::deleteElem(Service& serv)
{
	int id = 0;
	cout << "Introduceti id-ul camerei pe care doriti sa o stergeti: ";
	cin >> id;
	RezervareCamera e = serv.findElemFromId(id);
	serv.deleteElem(e);
	cout << "Camera stearsa cu succes!" << endl << endl;
}

//actualizarea unei camere
void UI::updateElem(Service& serv)
{
	int id = 0;
	char* tip = new char[10];
	char* nr = new char[10];
	bool eliberata =true;
	cout << "Introduceti id-ul camerei pe care doriti sa o actualizati: ";
	cin >> id;
	RezervareCamera e = serv.findElemFromId(id);
	cout << "Introduceti numarul camerei: ";
	cin >> nr;
	cout << "Introduceti tipul camerei: ";
	cin >> tip;
	cout << "Introduceti statusul camerei (1/0): ";
	cin >> eliberata;
	RezervareCamera new_e = RezervareCamera(id, nr, tip, eliberata);
	serv.update(e, new_e);
	cout << "Camera actualizata cu succes!" << endl << endl;
}

//afiseaza toate camerele eliberate din vector
void UI::afisare_elib(Service& serv) {
	vector<RezervareCamera> elem = serv.getAll();
	int k = 0;
	for (int i = 0; i < elem.size(); i++) {
		if (elem[i].getEliberata() == true)
		{
			cout << k + 1 << ".) ";
			elem[i].afisare();
			cout << endl;
			k++;
		}
	}
	cout << endl;
}

//afiseaza procentajul fiecarui tip de camera
void UI::afisare_procentaj(Service& serv) {
	int v[3];
	serv.procentaj(repo, v);
	for (int i = 0; i < 3; i++)
	{
		int nr = 0;
		int ultim = 0;
		ultim = v[i] % 10;
		nr = v[i] / 10;
		if (ultim == 1)
			cout << "Simpla: " << nr << "%;" << endl;
		if (ultim == 2)
			cout << "Dubla: " << nr << "%;" << endl;
		if (ultim == 3)
			cout << "Vip: " << nr << "%;" << endl;
	}
	cout << endl;
}


//afiseaza toate elementele din vector
void UI::afisare(Service& serv) {
	vector<RezervareCamera> elem = serv.getAll();
	for (int i = 0; i < elem.size(); i++) {
		cout << i + 1 << ".) ";
		elem[i].afisare();
		cout << endl;
	}
	cout << endl;
}

//afiseaza elementele din fisier
void UI::afisareFisier(Service& serv)
{
	cout << "Elementele din fisier: " << endl;
	vector<RezervareCamera> elem = serv.getAll();
	for (int i = 0; i < elem.size(); i++) {
		cout << i + 1 << ".) ";
		elem[i].afisare();
		cout << endl;
	}
}

//citirea optiunii
int UI::get_input()
{
	int choice;
	cin >> choice;
	return choice;
}

//afiseaza optiunile din meniu
void UI::afisare_meniu()
{
	cout << endl;
	cout << "Meniul:\n";
	cout << "1 - Adauga camera \n";
	cout << "2 - Sterge camera \n";
	cout << "3 - Actualizeaza camera \n";
	cout << "4 - Functionalitate afisare procentaj \n";
	cout << "10 - Afisare camere \n";
	cout << "11 - Exit \n";
	cout << endl;
	cout << "Alegeti o optiune: ";
}

//incarca elemente in service
void UI::incarcaElemente(Service& serv)
{
	RezervareCamera e1 = RezervareCamera(1, "A123", "dubla", true);
	serv.adauga(e1);
	RezervareCamera e2 = RezervareCamera(2, "P19", "simpla",true);
	serv.adauga(e2);
	RezervareCamera e3 = RezervareCamera(3, "C3","dubla", false);
	serv.adauga(e3);
	RezervareCamera e4 = RezervareCamera(4, "B34", "dubla", false);
	serv.adauga(e4);
	RezervareCamera e5 = RezervareCamera(5, "T17", "vip", false);
	serv.adauga(e5);
	RezervareCamera e6 = RezervareCamera(6, "A9", "vip", false);
	serv.adauga(e6);
}