#pragma once
#include "repository.h"
#include <assert.h>
#include "Cos.h"
#include "FileRepository.h"
#include "undo.h"
class Service
{private:
	//Initializam repo si validato deoare le vom folosi
	RepositoryMain& repo;
	validation& validator;
	//entitate pentru meniul de cos
	Cos cos;

	

public:
	//UndoAdauga addUndo{ repo };
	UndoSterge delUndo{ repo };
	UndoModifica modUndo{ repo };
	UndoAdauga addUndo{ repo };
		int prob;
	//constructori
	Service(RepositoryMain& repo, validation& validator) :repo{ repo }, validator{ validator }{};
	//vrem sa nu se poate copia asa ca ii blocam constructorul de copiere
	Service(const Service& cop) = delete;

	//Functie ce cauta un film in memorie cu titlul dat si returneaza filmul daca il gaseste
	const Film& find(string titlu);
	//Functie ce cauta un film in memorie cu titlul dat si cu genul dat si returneaza filmul daca il gaseste
	const Film& find_by_2(string titlu, string gen);
	
	//Functie ce adauga un film cu datele in memorie
	//throw validation Exeption daca una dintre date nu este valida
	void addFilm(string titlu, string gen, int an_ap, string actor);
	
	//Functie ce returneaza toate filmele din memorie sub forma unui vector din stl
	const vector<Film>& getFilme() {
		return this->repo.getAll();
	}
	
	//Functie ce returneaza toate filmele din memorie ce au un titlu "titlu" sub foma unui vector 
	vector<Film> filter_by_titlu(string titlu);
	//Functie ce returneaza toate filmele din memorie ce au un an "an" sub foma unui vectorDinamic
	vector<Film> filter_by_an(int an);
	
	//Functie ce sterge primul film din memorie ce are titlul dat
	void delete_film(string titlu);
	

	//Functie de sortare generala , primeste ca parametru o functie de comparare a doua entitati de tip film
	//returneaza filmele din memorie sortate dupa functia data sun forma unui vector
	vector<Film> generalSort(bool(*maiMicF)(const Film&, const Film&));
	
	//Functie ce sorteaza in functie de titlu crescator
	vector<Film> sortTitlu();

	//Functie ce sorteaza in functie de an cresacator
	vector<Film> sortAn();

	//Functie ce sorteaza in functie de actor creescator
	vector<Film> sortActor();
	

	// Functie ce moifuca un film din memori ce are titlul dat cu new_titlu si new_an
	void modify_film(string titlu, string new_tiltu, int new_an);

	//Functie ce adauga un film in "cos"
	//filmul trebuie sa existe in memorie deja si sa aiba titlul si genul dat ca parametrii
	void addFilmToCos(string titlu, string gen);

	//functie ce strege toate filmele din cos
	void clearCos();

	//Functie ce adauga un numar (cant) de filme random dintre cele existente deja in memore
	int addRandom(int cant);

	//functie ce returneaza vectorul cu toate elementele din cos
	const vector<Film>& getCos();

	void fis_cmd(string filename);

	
};

//teste
void test_Service();
void test_serv_add();
void test_serv_find();
void test_serv_del();
void test_filter();
void test_sort();
void test_cos1();
void test_generate_cos();

void test_undo_add();