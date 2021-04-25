#include "Coada.hpp"
#include <iomanip>

Coada::Coada(Team *TEAM1, Team *TEAM2) {
	team1 = TEAM1;
	team2 = TEAM2;
	next = NULL;
}

Coada* Coada::add_Node(Team *TEAM1, Team *TEAM2) {
	if(team1 == NULL) {
		team1 = TEAM1;
		team2 = TEAM2;
		return this;
	}
	Coada *coada = new Coada(TEAM1, TEAM2);
	coada->next = this;
	return coada;
}

void Coada::read(Team **TEAM1, Team **TEAM2) {
	Coada *tmp = this;
	if(this->next == NULL) {
		TEAM1[0] = team1;
		TEAM2[0] = team2;
		team1 = NULL;
		team2 = NULL;
		return;
	}
	while(tmp->next->next != NULL)
		tmp=tmp->next;
	TEAM1[0] = tmp->next->team1;
	TEAM2[0] = tmp->next->team2;
	delete tmp->next;
	tmp->next = NULL;
}

int Coada::coada_List(Coada **coada, List *list) {
	int nr=0;
	if(list == NULL)
		return nr;
	nr += coada_List(coada,list->get_Next()->get_Next());
	coada[0] = coada[0]->add_Node(list->get_Next()->get_Team(), list->get_Team());
	return ++nr;
}

bool Coada::is_Empty() const {
	if(team1 == NULL)
		return true;
	return false;
}
