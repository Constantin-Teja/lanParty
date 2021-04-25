#include "List.hpp"
#include "Stiva.hpp"
#include "AVL.hpp"

// Joaca toate meciurile si le scrie in fisier. Castigatorii si pierzatorii sunt pusi in stive
void play_Round(Coada *coada, Stiva **winners, Stiva **losers, ofstream& out) {
	while(coada->is_Empty() == false) {
		Team *TEAM1, *TEAM2;
		coada->read(&TEAM1, &TEAM2);
		out<<TEAM1->get_Name()<<setw(34 - TEAM1->get_Name().length())<<"-"<<setw(33)<<TEAM2->get_Name()<<"\n";
		if(TEAM1->get_Points() > TEAM2->get_Points()) {
			TEAM1->add_Point();
			winners[0] = winners[0]->add_Node(TEAM1);
			losers[0] = losers[0]->add_Node(TEAM2);
		}
		else {
			TEAM2->add_Point();
			winners[0] = winners[0]->add_Node(TEAM2);
			losers[0] = losers[0]->add_Node(TEAM1);
		}
	}
}


void write_Stiva(Stiva **stiva, ofstream &out, Coada **coada) {
	if (stiva[0]->is_One()) {
		Team *TEAM;
		if(coada != NULL) {
			stiva[0]->read(&TEAM, stiva);
			out<<"\n"<<fixed<<setprecision(2)<<TEAM->get_Name()<<setw(35 - TEAM->get_Name().length())<<"-"<<"  "<<TEAM->get_Points();
		}
		else  {
			Stiva *tmp = stiva[0];
			stiva[0]->read(NULL, stiva);
			delete tmp;
		}
	}
	else
		while(stiva[0] != NULL) {
			if(coada != NULL) {
				Team *TEAM1, *TEAM2;
				stiva[0]->read(&TEAM1, stiva);
				stiva[0]->read(&TEAM2, stiva);
				out<<"\n"<<TEAM1->get_Name()<<setw(35 - TEAM1->get_Name().length())<<"-"<<"  "<<TEAM1->get_Points();
				out<<"\n"<<TEAM2->get_Name()<<setw(35 - TEAM2->get_Name().length())<<"-"<<"  "<<TEAM2->get_Points();
				coada[0] = coada[0]->add_Node(TEAM1,TEAM2);
			}
			else {
				Stiva *tmp = stiva[0];
				stiva[0]->read(NULL, stiva);
				delete tmp;
				tmp = stiva[0];
				stiva[0]->read(NULL, stiva);
				delete tmp;
			}
		}
}

int main(int argc, char **argv) {
	//	Verificare daca sunt date suficiente argumente
	if(argc < 4) {
		cout<<"\tPrea putine argumente!"<<endl;
		return 0;
	}


	// Deschiderea fisierelor si testarea daca au fost deschise fara eroare
	ifstream c(argv[1]);
	ifstream in(argv[2]);
	ofstream out(argv[3]);
	if(!c) {
		cout<<"\tFisierul "<<argv[1]<<" nu s-a putut deschide!"<<endl;
		return 0;
	}
	if(!in) {
		cout<<"\tFisierul "<<argv[2]<<" nu s-a putut deschide!"<<endl;
		return 0;
	}
	if(!out) {
		cout<<"\tFisierul "<<argv[3]<<" nu s-a putut deschide!"<<endl;
		return 0;
	}

	// Citirea din fisierul cerinta
	int cc[5];
	c>>cc[0];
	c>>cc[1];
	c>>cc[2];
	c>>cc[3];
	c>>cc[4];
	c.close();

	// Crearea listei si scrierea acesteia in rezultate
	int nr;
	in>>nr;
	List *list = new List(in, nr);
	if(cc[0] == 1) {
		list->get_Next()->write(out);
		out<<list->get_Team()->get_Name();
	}
	in.close();
	
	  // DE TEST PTR CER 2 !!! DE MODIFICAT
	if(cc[1] == 1) {
		out.close();
		out.open(argv[3]);
		if(!out) {
			cout<<"\tFisierul "<<argv[3]<<" nu s-a putut deschide!"<<endl;
			return 0;
		}
		List *cap_Delete = NULL;
		list = list->eliminate_Teams(nr, &cap_Delete);
		if(cap_Delete != NULL) {
			cap_Delete->set_Next(NULL);
			delete cap_Delete->get_Team();
			delete cap_Delete;
		}
		list->get_Next()->write(out);
		out<<list->get_Team()->get_Name();
	}

	if(cc[2] == 1) {
		out<<fixed<<setprecision(2);
		Coada *coada = new Coada(NULL,NULL);
		nr = 0;
		nr = Coada::coada_List(&coada, list);

		unsigned int rounds = 1;
		while(nr != 0) {
			Stiva *winners = new Stiva();
			Stiva *losers = new Stiva();
			out<<"\n\n--- ROUND NO:"<<rounds<<"\n";
			play_Round(coada, &winners, &losers, out);  // Creeaza stiva de castigatori si cea de invinsi
			nr/=2;

			out<<"\nWINNERS OF ROUND NO:"<<rounds;
			if(nr == 4) {
				list = winners->create_List();			// TREBUIE SA FAC ALTA STIVA SAU POT SI ASA ????
				//list->write(out);
			}
			write_Stiva(&winners, out, &coada);
			write_Stiva(&losers, out, NULL);
			rounds++;
		}

	}

	List *list_AVL = new List();
	BST *root_BST = NULL;
	if(cc[3] == 1) {
		List *tmp = list->get_Next();
		root_BST = new BST(list->get_Team());
		while(tmp != NULL) {
			root_BST->add_Node(root_BST, tmp->get_Team());
			tmp = tmp->get_Next();
		}
		out<<"\n\nTOP 8 TEAMS:";
		root_BST->write(root_BST, out, list_AVL);
		delete root_BST;
	}

	if(cc[4] == 1) {
		List *tmp = list_AVL->get_Next();
		AVL *root_AVL = new AVL(list_AVL->get_Team());

		while(tmp != NULL) {
			root_AVL = root_AVL->add_Node(root_AVL, tmp->get_Team());
			tmp = tmp->get_Next();
		}
		root_AVL->print_NIV2(out);
		delete root_AVL;
	}


	// Eliberez memoria ocupata de echipe si de arborele AVL
	List *temp = list_AVL;
	while(temp != NULL) {
		list_AVL = temp;
		temp = temp->get_Next();
		list_AVL->set_Next(NULL);
		delete list_AVL->get_Team();
		delete list_AVL;
	}

	out.close();
	return 0;

}