#pragma once
#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

class Player {
private:
    string firstName;		// Nume
    string secondName;		// Prenume
    int points;				// Puncte

public:
	void set_firstName(string);			// Seteaza Numele
	void set_secondName(string);		// Seteaza Prenumele
	void set_points(int);				// Seteaza Punctele
	int get_points() const;				// Returneaza Punctele
	Player& operator=(const Player&);	// Operatorul =
};