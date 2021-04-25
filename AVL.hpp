#include "BST.hpp"

class AVL {
private:
	int height;
	Team *team;
	AVL *left, *right;
public:
	AVL(Team*);							// Constructior fara parametrii
	~AVL();								// Destructor
	AVL* add_Node(AVL*, Team*);			// Adauga un nod arborelui
	AVL* right_Rotation(AVL*);
	AVL* left_Rotation(AVL*);
	static int get_Height(AVL*);		// Returneaza inaltimea nodului
	static int max_Height(int,int);		// Returneaza inaltimea maxima
	static AVL* create_AVL(AVL*,List*);	// Creeaza arborele AVL folosind cel BST
	void print_NIV2(ofstream&) const;	// Afiseaza nivelul 2
};