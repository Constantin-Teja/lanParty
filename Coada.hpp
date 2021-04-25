#include "List.hpp"

class Coada {
private:
	Team *team1, *team2;	// Echipele corespunzzatoare meciului
	Coada *next;			// Pointer catre meciul urmator din coada
public:
	Coada(Team*, Team*);							// Constructor de creare nod
	Coada* add_Node(Team*, Team*);					// Adauga un nod cozii
	void read(Team**,Team**);						// Returneaza prin cei doi parametrii echipele corespunzatoare meciului
	static int coada_List(Coada**,List*);			// Creeaza coada folosind echipele din lista. Returneaza numarul de meciuri
	bool is_Empty() const;							// Verifica daca coada e goala
};


		// 		Nu este nevoie de implementarea destructorului deoarece 
		//	nu vreau sa sterg nici echipele si nici urmatorul meci
		//	deoarece le stochez in stive.