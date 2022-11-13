#pragma once
#include "Film.h"
#include <vector>
#include "validation.h"
#include <assert.h>
#include <map>

using std::map;
using std::vector;
//#include "vectorDinamic.h"

//Modul ce se ocupa cu gestiunea memoriei si cu legatura dintre aceasta si aplicatie
class RepoException {
	//clasa pentru gestionarea exceptilor ce pot aparea
private:
	//exceptile sub forma de string
	string errMsg;
public:
	RepoException(string errMsg) : errMsg{ errMsg } {};
	//functie ce returneaza totate erorile descoperite sub forma de string
	string getMsg() {
		return this->errMsg;
	}
};


class RepositoryMain
{
private:
	//vectorul in care tinem toate entitatile de tip film
	//vector<Film> allFilme;
	
public:

	int prob;
	//constructori
	RepositoryMain() = default;
	RepositoryMain(const RepositoryMain& re) = delete;

	//functie pentru adaugarea unui nou film in memorie
	virtual void addFilm(const Film& new_film)=0;

	//verifica daca un film exista sau nu deja in memorie
	//return true daca nu exista, false altfel
	virtual bool exista(const Film& f)=0;

	//functie ce verifica daca un film cu titlul dat se afla in memorie 
	//return filmul gasit daca exista
	//daca nu exista throw RepoException
	virtual const Film& find(string titlu)=0;

	//functie ce verifica daca un film cu titlul dat si cu genul dat se afla in memorie 
	//return filmul gasit daca exista
	//daca nu exista throw RepoException
	virtual const Film& find2(string titlu, string gen)=0;

	//functie ce returneaza toate filmele din memorie sub forma unui vector din stl
	virtual const vector<Film>& getAll()=0;

	//Functie ce sterge un film cu titlul dat din memorie
	virtual virtual void delete_film(string titlu)=0;

	//Functie ce modifica primul film cu titlul dat din memorie
	//ii inlocuieste titlul cu new_titlu si anul cu new_an
	virtual void modify_film(string titlu, string new_tiltu, int new_an)=0;

};


class Repository:public RepositoryMain
{
private:
	//vectorul in care tinem toate entitatile de tip film
	vector<Film> allFilme;

public:


	//constructori
	Repository() = default;
	Repository(const Repository& re) = delete;

	//functie pentru adaugarea unui nou film in memorie
	virtual void addFilm(const Film& new_film) override;
	
	//verifica daca un film exista sau nu deja in memorie
	//return true daca nu exista, false altfel
	bool exista(const Film& f) override;
	
	//functie ce verifica daca un film cu titlul dat se afla in memorie 
	//return filmul gasit daca exista
	//daca nu exista throw RepoException
	const Film& find(string titlu) override;
	
	//functie ce verifica daca un film cu titlul dat si cu genul dat se afla in memorie 
	//return filmul gasit daca exista
	//daca nu exista throw RepoException
	const Film& find2(string titlu,string gen) override;
	
	//functie ce returneaza toate filmele din memorie sub forma unui vector din stl
	const vector<Film>& getAll() override;

	//Functie ce sterge un film cu titlul dat din memorie
	virtual void delete_film(string titlu)override;
	
	//Functie ce modifica primul film cu titlul dat din memorie
	//ii inlocuieste titlul cu new_titlu si anul cu new_an
	void modify_film(string titlu, string new_tiltu, int new_an)override;

};
//teste
void repo_tests();

void repo_test_add();
void repo_test_find();
void repo_test_modify();
void repo_test_delete();

class RepositoryMap :public RepositoryMain {

private:
	//vectorul in care tinem toate entitatile de tip film
	//vector<Film> allFilme;
	map<int,Film> allFilme;
	int id = 1;
public:


	//constructori
	RepositoryMap() = default;
	RepositoryMap(const RepositoryMap & re) = delete;

	//functie pentru adaugarea unui nou film in memorie
	virtual void addFilm(const Film & new_film);

	//verifica daca un film exista sau nu deja in memorie
	//return true daca nu exista, false altfel
	bool exista(const Film & f);

	//functie ce verifica daca un film cu titlul dat se afla in memorie 
	//return filmul gasit daca exista
	//daca nu exista throw RepoException
	const Film& find(string titlu);

	//functie ce verifica daca un film cu titlul dat si cu genul dat se afla in memorie 
	//return filmul gasit daca exista
	//daca nu exista throw RepoException
	const Film& find2(string titlu, string gen);

	//functie ce returneaza toate filmele din memorie sub forma unui vector din stl
	const vector<Film>& getAll();

	//Functie ce sterge un film cu titlul dat din memorie
	virtual void delete_film(string titlu);

	//Functie ce modifica primul film cu titlul dat din memorie
	//ii inlocuieste titlul cu new_titlu si anul cu new_an
	void modify_film(string titlu, string new_tiltu, int new_an);


};