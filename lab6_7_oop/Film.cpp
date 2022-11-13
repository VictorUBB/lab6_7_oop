#include "Film.h"


string Film::getTitlu() const {
	return this->titlu;
}
string Film::getGen() const {
	return this->gen;
}
int Film::getAn() const {
	return this->anul_aparitiei;
}
string Film::getActor() const {
	return this->actor_principal;
}

void Film::setTitlu(string new_titlu) {
	this->titlu = new_titlu;
}
void Film::setGen(string new_gen) {
	this->gen = new_gen;
}
void Film::setAn(int new_an) {
	this->anul_aparitiei = new_an;
}
void Film::setActor(string new_actor) {
	this->actor_principal = new_actor;
}

bool cmpTitlu(const Film& f1, const Film& f2)
{
	return f1.getTitlu() < f2.getTitlu();

}

bool cmpActor(const Film& f1, const Film& f2)
{
	return f1.getActor() < f2.getActor();
}

bool cmpAn(const Film& f1, const Film& f2)
{
	if (f1.getAn() == f2.getAn()) {
		return f1.getGen() < f2.getGen();
	}
	return f1.getAn() < f2.getAn();
}

void testCreate() {
	Film film1{ "batman","drama",2005,"Ana" };
	assert(film1.getTitlu() == "batman");
	assert(film1.getGen() == "drama");
	assert(film1.getAn() == 2005);
	assert(film1.getActor() == "Ana");
	film1.setActor("Andrei");
	assert(film1.getActor() == "Andrei");
	film1.setAn(2004);
	assert(film1.getAn() == 2004);
	film1.setGen("comedie");
	assert(film1.getGen() == "comedie");
	film1.setTitlu("abc");
	assert(film1.getTitlu() == "abc");
	//delete[] film1;

}