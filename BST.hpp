#include "Team.hpp"
#include "List.hpp"
#include <iomanip>

class BST {
private:
	Team *team;
	BST *left, *right;
public:
	BST(Team*);									// Constructor de creeare nod
	~BST();										// Destructor
	BST* add_Node(BST* ,Team*);					// Adauga un Node in arbore
	void write(BST*, ofstream&, List*) const;	// Afiseaza descrescator elementele arborelui
	Team* get_Team();							// Returneaza echipa
	BST* get_Right();
	BST* get_Left();
};