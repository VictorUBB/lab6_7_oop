#pragma once
#include <iostream>
#include <string>
#include <assert.h>
using std::string;
using std::cout;
class Film
{
private:
	string titlu;
	string gen;
	int anul_aparitiei;
	string actor_principal;

public:
	Film() = default;
	Film(string titlu, string gen, int anul_aparitiei, string actor_principal) :titlu{ titlu }, gen{ gen }, anul_aparitiei{ anul_aparitiei }, actor_principal{ actor_principal }{};
	Film(const Film& fi):titlu{ fi.titlu }, gen{ fi.gen }, anul_aparitiei{ fi.anul_aparitiei }, actor_principal{ fi.actor_principal }{};

	
	string getTitlu() const;
	string getGen() const;
	int getAn() const;
	string getActor() const;

	void setTitlu(string new_titlu);
	void setGen(string new_gen);
	void setAn(int new_an);
	void setActor(string new_actor);


};


	bool cmpTitlu(const Film& f1, const Film& f2);
	bool cmpActor(const Film& f1, const Film& f2);
	bool cmpAn(const Film& f1, const Film& f2);
	void testCreate();