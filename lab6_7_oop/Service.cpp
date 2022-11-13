#include "Service.h"
#include <iterator>
#include <algorithm>
#include <functional>
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
using std::string;
using std::iterator;

const Film& Service::find(string titlu)
{
	try {
		return repo.find(titlu);
	}
	catch (RepoException& re) {
		cout << re.getMsg();
	}
	
}

void Service::addFilm(string titlu, string gen, int an_ap, string actor)
{
	Film new_film{ titlu, gen, an_ap, actor };
	validator.valideaza(new_film);
	try {
		repo.addFilm(new_film);
	}
	catch (RepoException& re) {
		cout << re.getMsg();
	}
	addUndo.add_to_undo(new_film);

}


vector<Film> Service::filter_by_titlu(string titlu)
{

	vector<Film> new_list;
	vector<Film>::iterator it;
	vector<Film> repo1 = getFilme();
	it = repo1.begin();
	std::copy_if(repo1.begin(), repo1.end(),std::back_inserter(new_list), [titlu](const Film& f) {return f.getTitlu() == titlu;});
	
	return new_list;


}

vector<Film> Service::filter_by_an(int an)
{

	vector<Film> new_list;
	//vector<Film>::iterator it;
	vector<Film> repo1 = getFilme();
	//it = repo1.begin();
	std::copy_if(repo1.begin(), repo1.end(), std::back_inserter(new_list), [an](const Film& f) {return f.getAn() == an;});

	return new_list;
}

void Service::delete_film(string titlu)
{
	Film f = repo.find(titlu);
	delUndo.add_to_del(f);
	try {
	repo.delete_film(titlu);
	}
	catch (RepoException& re) {
		cout << re.getMsg();
	}


}

vector<Film> Service::generalSort(bool(*maiMicF)(const Film&, const Film&))
{
	try {
	vector<Film> repo1 = getFilme();


	std::sort(repo1.begin(), repo1.end(), maiMicF);
return repo1;
	}
	catch (RepoException& re) {
		cout << re.getMsg();
	}
	
}

vector<Film> Service::sortTitlu()
{	
	return generalSort(cmpTitlu);
}

vector<Film> Service::sortAn()
{
	return generalSort(cmpAn);
}

vector<Film> Service::sortActor()
{
	return generalSort(cmpActor);
}

void Service::modify_film(string titlu, string new_tiltu, int new_an)
{try{
	Film f = find(titlu);
	repo.modify_film(titlu, new_tiltu, new_an);
	modUndo.add_to_mod(titlu, new_tiltu, f.getAn());
}
catch (RepoException& re) {
	cout << re.getMsg();
}
}

const Film& Service::find_by_2(string titlu, string gen)
{
	try {
	return repo.find2(titlu, gen);
}
	catch (RepoException& re) {
		cout << re.getMsg();
	}
}

void Service::addFilmToCos(string titlu, string gen)
{
	try {
	Film f = repo.find2(titlu, gen);
	cos.addFilmToC(f);
}
	catch (RepoException& re) {
		cout << re.getMsg();
	}
}

void Service::clearCos()
{
	cos.clearCos();
}

int Service::addRandom(int cant)
{
	try {


	vector<Film> mem = repo.getAll();
	cos.generateCos(mem, cant);
	return cos.getCos().size();
	}
	catch (RepoException& re) {
		cout << re.getMsg();
	}
}

const vector<Film>& Service::getCos()
{
	return cos.getCos();
}

void Service::fis_cmd(string filename)
{
	std::ifstream f(filename);
	while (!f.eof()) {
		string cmd;
		f >> cmd;
		if (cmd == "add") {
			string titlu, gen, actor;
			int an;
			f >> titlu >> gen >> an >> actor;
			addFilm(titlu, gen, an, actor);
		}
		else if (cmd == "delete") {
			string titlu1;
			f >> titlu1;
			delete_film(titlu1);
		}
		else if (cmd == "update") {
			string titlu2, new_titlu;
			int new_an;
			f >> titlu2 >> new_titlu >> new_an;
			modify_film(titlu2, new_titlu, new_an);
		}
		else {
			cout << "Nu exista optiunea data";
			break;
		}


	}

}

void test_Service()
{
	test_serv_add();
	test_serv_find();
	test_serv_del();
	test_filter();
	test_sort();
	test_cos1();
}

void test_cos1() {

	Repository repo;
	validation val;
	Service test_serv{ repo,val };
	//Cos cos;
	string titlu;
	titlu = "batman";
	string gen = "drama";
	int an = 2002;
	string actor = "Gion";
	Film f{ titlu,gen,an,actor };
	repo.addFilm(f);
	test_serv.addFilmToCos(titlu, gen);
	vector<Film> vect;
	vect = test_serv.getCos();
	assert(vect.size() == 1);
	test_serv.clearCos();
	vect = test_serv.getCos();
	assert(vect.size() == 0);
	test_generate_cos();
}

void test_generate_cos()
{
	Repository repo;
	validation val;
	Service test_serv{ repo,val };
	string titlu;
	titlu = "batman";
	string gen = "drama";
	int an = 2002;
	string actor = "Gion";
	Film f{ titlu,gen,an,actor };
	repo.addFilm(f);
	titlu = "superman";
	gen = "comedie";
	an = 2009;
	actor = "eu";
	Film f1{ titlu,gen,an,actor };
	repo.addFilm(f1);
	titlu = "ana";
	gen = "comedie";
	an = 2019;
	actor = "el";
	Film f2{ titlu,gen,an,actor };
	repo.addFilm(f2);
	int cant = 2;
	int added = test_serv.addRandom(cant);
	vector<Film> test_v = test_serv.getCos();
	assert(test_v.size() == 2);
	assert(added == 2);
	cant = 3;
	added = test_serv.addRandom(cant);
	test_v = test_serv.getCos();
	assert(test_v.size() == 3);
}

void test_serv_add()
{
	Repository repo;
	validation val;
	Service test_serv{ repo,val };
	string titlu = "Batman";
	string gen = "comedie";
	int an = 2020;
	string actor = "eu";
	test_serv.addFilm(titlu, gen, an, actor);
	vector<Film> vect = test_serv.getFilme();
	assert(vect.size() == 1);
	vector<Film>::iterator it=vect.begin();
	assert((*it).getActor() == actor);
	assert((*it).getAn() == an);
	assert((*it).getGen() == gen);
	assert((*it).getTitlu() == titlu);

}

void test_serv_find() {
	Repository repo;
	validation val;
	Service test_serv{ repo,val };
	string titlu = "Batman";
	string gen = "comedie";
	int an = 2020;
	string actor = "eu";
	test_serv.addFilm(titlu, gen, an, actor);
	string tit1 = "Superman";
	string gen1 = "drama";
	string actor1 = "El";
	int an1 = 2003;
	test_serv.addFilm(tit1, gen1, an1, actor1);
	Film f1 = test_serv.find(tit1);
	assert(f1.getActor() == actor1);
	assert(f1.getTitlu() == tit1);
	Film f2 = test_serv.find_by_2(titlu, gen);
	assert(f2.getActor() == actor);
	assert(f2.getGen() == gen);
}

void test_serv_del() {
	Repository repo;
	validation val;
	Service test_serv{ repo,val };
	string titlu = "Batman";
	string gen = "comedie";
	int an = 2020;
	string actor = "eu";
	test_serv.addFilm(titlu, gen, an, actor);
	try {
	test_serv.delete_film(titlu);
	}
	catch (RepoException& re) {

	}

	vector<Film> vect = test_serv.getFilme();
	assert(vect.size() == 0);

}

void test_filter() {
	Repository repo;
	validation val;
	Service test_serv{ repo,val };
	string titlu = "Batman";
	string gen = "comedie";
	int an = 2020;
	string actor = "eu";
	test_serv.addFilm(titlu, gen, an, actor);
	string tit1 = "Superman";
	string gen1 = "drama";
	string actor1 = "El";
	int an1 = 2003;
	test_serv.addFilm(tit1, gen1, an1, actor1);
	string tit2 = "Batman";
	string gen2 = "actiune";
	int an2 = 2003;
	string act3 = "Voi";
	test_serv.addFilm(tit2, gen2, an2, act3);
	vector<Film> test_vect = test_serv.filter_by_an(an2);
	assert(test_vect.size() == 2);
	test_vect = test_serv.filter_by_titlu(titlu);
	assert(test_vect.size() == 2);
}

void test_sort() {
	Repository repo;
	validation val;
	Service test_serv{ repo,val };
	string titlu = "Batman";
	string gen = "comedie";
	int an = 2007;
	string actor = "eu";
	test_serv.addFilm(titlu, gen, an, actor);
	string tit1 = "Superman";
	string gen1 = "drama";
	string actor1 = "El";
	int an1 = 2020;
	test_serv.addFilm(tit1, gen1, an1, actor1);
	string tit2 = "Ana";
	string gen2 = "actiune";
	int an2 = 2003;
	string act3 = "Voi";
	test_serv.addFilm(tit2, gen2, an2, act3);

	vector<Film> test_vect = test_serv.sortAn();
	vector<Film>::iterator it=test_vect.begin();
	Film f1 = (*it);
	it++;
	Film f2 = (*it);
	it++;
	assert(f1.getAn() <= (f2).getAn());
	assert(f2.getAn() <= (*it).getAn());

	test_vect = test_serv.sortActor();
	vector<Film>::iterator it1 = test_vect.begin();
	Film f11 = (*it1);
	it1++;
	Film f21 = (*it1);
	it1++;
	assert(f21.getActor() <= (*it1).getActor());

	test_vect = test_serv.sortTitlu();
	vector<Film>::iterator it2 = test_vect.begin();
	Film f12 = (*it2);
	it2++;
	Film f22 = (*it2);
	it2++;
	assert(f12.getTitlu() <= f22.getTitlu());
	assert(f22.getTitlu() <= (*it2).getTitlu());
}

void test_undo_add() {
	Repository repo;
	//UndoAdauga test_add{ repo };
	validation val;
	Service serv{ repo,val };
	Film f{ "batman","drama",2010,"vicctor" };
	serv.addFilm("batman", "drama", 2010, "vicctor");
	Film f2{ "superman","comedie",2011,"eu" };
	serv.addFilm("superman", "comedie", 2011, "eu");
	serv.addUndo.doUndo();
	assert(repo.getAll().size() == 1);
	Film f3 = repo.find("batman");
	assert(f3.getAn() == f.getAn());
	assert(f3.getGen() == f.getGen());
}
