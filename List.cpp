#include "List.hpp"

List::List(Team *TEAM) {
	team = TEAM;
	next = NULL;
}

List::List(ifstream &in, int n) {
	team = NULL;
	next = NULL;
	for(int i=0; i<n; i++) {
		Team* TEAM = new Team(in);
		this->add_Node(TEAM);
	}
}

List::~List() {
	delete next;
}

void List::add_Node(Team *TEAM) {
	if(team == NULL) {
		team = TEAM;
		return;
	}

	List *tmp = this;
	while(tmp->next !=NULL)
		tmp = tmp->next;

	tmp->next = new List(TEAM);
}

Team* List::get_Team() const {
	return team;
}

void List::write(ofstream &out) const {
	if(this->next != NULL)
		this->next->write(out);
	out<<this->team->get_Name()<<"\n";
}

List* List::eliminate_Teams(int nr, List **cap_Delete) {

	// Calculez numarul de echipe care trebuie sa ramana
	int n = 1;
	while(true) {
		if(n*2 > nr)
			break;
		n *= 2;
	}
	// Fac eliminarea echipelor pana numarul de echipe din lista ajunge la numarul n calculat mai sus
	List *tmp = this;

	while(nr != n) {
		List *min_Node = tmp;
		double min = tmp->team->get_Points();
		tmp = tmp->next;
		
		// Aflu echipa cu cel mai mic punctaj  !!! DE GANDIT DACA O SCRIU CA FUNCTIE INLINE IN Team.hpp
		for(int i=1; i<nr; i++) {
			if(tmp->team->get_Points() <= min) {
				min = tmp->team->get_Points();
				min_Node = tmp;
			}
			tmp = tmp->next;
		}

		// Sterg echipa cu cel mai mic punctaj
		tmp = remove_Node(min_Node, cap_Delete);
		nr--;
	}
	return tmp;
}

List* List::remove_Node(List *node, List **cap_Delete) {
	if(this == node) {
		cap_Delete[0] = this;
		return this->next;
	}
	if(this->next == node && cap_Delete[0] != NULL) {
		this->next = node->next;
		node->next = NULL;
		delete node->team;
		delete node;
		return this->next;
	}

	List *tmp = this;
	while(tmp->next != node)
		tmp = tmp->next;

	tmp->next = node->next;
	node->next = NULL;
	delete node->team;
	delete node;
	if(cap_Delete[0] == NULL)
		return this;
	return this->next;
}

void List::set_Next(List *node) {
	next = node;
}

List* List::get_Next() const {
	return next;
}