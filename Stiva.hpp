#include "Team.hpp"
#include "Coada.hpp"
#include <iomanip>

class Stiva {
private:
	Team *team;			// Echipa corespunzatoare nodului din stiva
	Stiva *next;		// Pointer catre urmatoarea echipa din stiva
public:
	Stiva(Team *TEAM = NULL);					// Constructor
	~Stiva();									// Destructor
	Stiva* add_Node(Team*);						// Adauga un nod stivei si returneaza adresa acestuia
	void read(Team**, Stiva**);					// Citeste din stiva, daca e stiva de castigatori nu sterge nodurile
	void write(ofstream&, Coada**);				// Daca e stiva cu castigatori ii afiseaza scrie in fisier
												// Daca e cea cu pierzatori ii scoate doar din stiva si sterge echipele
	bool is_One() const;						// Returneaza true daca mai e doar o echipa in stiva
	List* create_List();						// Creeaza o lista cu echipele din stiva
};