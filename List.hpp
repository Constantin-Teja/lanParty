#pragma once
#include "Team.hpp"

class List {
private:
	Team *team;			// Echipa corespunzatoare nodului
	List *next;			// Pointer catre urmatorul element din lista

public:
	List(Team *TEAM = NULL);			// Constructor. Daca echipa nu e nula creeaza un nod cu echipa data ca parametru
	List(ifstream&, int n);				// Constructor. Creeaza o lista cu elemente primele n echipe din fisierul dat ca parametru
	~List();							// Destructor
	void add_Node(Team*);				// Adauga o echipa listei
	Team* get_Team() const;				// Returneaza echipa corespunzatoare nodului
	void write(ofstream&) const;		// Afiseaza Numele echipelor in fisierul dat ca parametru
	List* eliminate_Teams(int, List**);	// Elimina echipele cu cele mai mici punctaje pana raman un numar (egal cu cea mai mare putere de 2 mai mica decat nr) de echipe.
	List* remove_Node(List*, List**);	// Sterge nodul dat in primul parametru, iar in al doilea pune pointer catre capul liste in cazul in care e unul din nodurile cu echipele eliminate
	void set_Next(List*);				// Seteaza urmatorul nod din lista
	List* get_Next() const;				// Returneaza echipa nodul urmator
};