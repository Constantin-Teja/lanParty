#pragma once
#include "Player.hpp"

class Team {
private:
	string name;		// Numele echipei
	unsigned int nr;	// Numarul de playeri din echipa
	Player *p;			// Vectorul de playeri din echipa  !!! DE INTREBAT DACA FAC LISTA SI PENTRU PLAYERI
	double points;		// Punctele echipei

public:
	Team(ifstream&);				// Constructor cu parametru fisierul din care se citesc playerii
	Team(Team*);					// Constructor de creare al unei echipe folosind informatiile echipei date ca parametru
	~Team();						// Destructorul
	void add_Players(ifstream&);	// Metoda pentru adaugarea playerilor in echipa prin citirea lor din fisierul  primit ca parametru
	string get_Name() const;		// Returneaza numele echipei
	double get_Points() const;		// Returneaza punctajul echipei
	void add_Point();				// Adauga 1 punct la punctajul echipei
};