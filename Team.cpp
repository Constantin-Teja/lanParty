#include "Team.hpp"

Team::Team(ifstream &in) {
	in>>nr;
	char buf[256];
	in.getline(buf, 255, '\n');
	name = buf;
	name = name.substr(1, name.length() - 1);
	while(name[name.length()-1] == ' ')
		name = name.substr(0,name.length()-1);
	name.reserve(0);			// Aceasta instructiune va reduce pierderile de memorie pentru stocarea numelui
	p = new Player[nr];
	add_Players(in);
	points = 0;
	for(int i=0; i<nr; i++)
		points += p[i].get_points();
	points = points/(double)nr;
}

Team::Team(Team* team) {
	name = team->name;
	nr = team->nr;
	p = new Player[nr];
	for(int i=0; i<nr; i++)
		p[i] = team->p[i];
	points = team->points;
}

Team::~Team() {
	delete[] p;
}

void Team::add_Players(ifstream& in) {
	for(int i=0; i<nr; i++) {
		string aux_string;
		int aux_int;
		in>>aux_string;
		p[i].set_firstName(aux_string);
		in>>aux_string;
		p[i].set_secondName(aux_string);
		in>>aux_int;
		p[i].set_points(aux_int);
	}
}

string Team::get_Name() const {
	return name;
}

double Team::get_Points() const {
	return points;
}

void Team::add_Point() {
	points++;
}