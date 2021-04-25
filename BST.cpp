#include "BST.hpp"

BST::BST(Team *TEAM) {
	team = TEAM;
	left = NULL;
	right = NULL;
}

BST::~BST() {
	delete left;
	delete right;
}

BST* BST::add_Node(BST *node, Team *TEAM) {
	if(node == NULL) {
		node = new BST(TEAM);
		return node;
	}
	if((TEAM->get_Points() < node->team->get_Points()) || ((TEAM->get_Points() == node->team->get_Points()) && (TEAM->get_Name() < node->team->get_Name())))
		node->left = add_Node(node->left, TEAM);
	else
		node->right = add_Node(node->right, TEAM);
	return node;
}

void BST::write(BST *node, ofstream& out, List *list) const {
	if(node == NULL)
		return;
	write(node->right, out, list);
	out<<"\n"<<node->team->get_Name()<<setw(35 - node->team->get_Name().length())<<"-"<<"  "<<node->team->get_Points();
	list->add_Node(node->team);
	write(node->left, out, list);
	return;
}

Team* BST::get_Team() {
	return team;
}

BST* BST::get_Right() {
	return right;
}

BST* BST::get_Left() {
	return left;
}