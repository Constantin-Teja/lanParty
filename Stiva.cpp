#include "Stiva.hpp"

Stiva::Stiva(Team *TEAM) {
	team = TEAM;
	next = NULL;
}

Stiva::~Stiva() {}

Stiva* Stiva::add_Node(Team *TEAM) {
	if(this->team == NULL) {
		team = TEAM;
		return this;
	}
	Stiva *tmp = new Stiva(TEAM);
	tmp->next = this;
	return tmp; 
}

void Stiva::read(Team **TEAM, Stiva **stiva) {
	if(TEAM == NULL) {
		stiva[0] = this->next;
		this->next = NULL;
		delete team;
		return;
	}
	TEAM[0] = team;
	stiva[0] = this->next;
	this->next = NULL;
	this->team = NULL;
}

bool Stiva::is_One() const {
	if(this->next == NULL)
		return true;
	return false;
}

List* Stiva::create_List() {
	Stiva *tmp = this;
	List *list = new List();
	while(tmp != NULL) {
		Team *TEAM = new Team(tmp->team);
		list->add_Node(TEAM);
		tmp = tmp->next;
	}
	return list;
}