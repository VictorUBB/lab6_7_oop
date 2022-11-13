#include "Repository.h"
#include <iterator>
#include <assert.h>
using std::iterator;

void Repository::addFilm(const Film& new_film)
{
	try {
		srand((unsigned)time(0));
		int ran = (rand() % 10) + 1;
		if (ran < prob)
			throw RepoException("random execp");
	}
	catch (RepoException& re) {
		cout << re.getMsg();
	}
	//if (exista(new_film))
	//	throw RepoException("Filmul cu titlul " + new_film.getTitlu() + " exista in memorie");
	//else
		this->allFilme.push_back(new_film);


}

bool Repository::exista(const Film& f)
{
	try {
		srand((unsigned)time(0));
		int ran = (rand() % 10) + 1;
		if (ran < prob)
			throw RepoException("random execp");
	}
	catch (RepoException& re) {
		cout << re.getMsg();
	}
	try {
		find(f.getTitlu());
		return true;
	}
	catch (RepoException) {
		return false;
	}
		

}

const Film& Repository::find(string titlu){
try {
	srand((unsigned)time(0));
	int ran = (rand() % 10) + 1;
	if (ran < prob)
		throw RepoException("random execp");
}
catch (RepoException& re) {
	cout << re.getMsg();
}
	//Iterator<Film> it = allFilme.begin();
	vector<Film>::iterator it;
	it = allFilme.begin();
	if (allFilme.size() > 0) {
		while (it!=allFilme.end()) {
			if ((*it).getTitlu() == titlu)
				return (*it);
			it++;
		}
		throw RepoException("Filmul cu titlul " + titlu + " nu exista in memorie \n");
	}
	throw RepoException("Filmul cu titlul " + titlu + " nu exista in memorie \n");
}

const Film& Repository::find2(string titlu, string gen)
{
	try {
		srand((unsigned)time(0));
		int ran = (rand() % 10) + 1;
		if (ran < prob)
			throw RepoException("random execp");
	}
	catch (RepoException& re) {
		cout << re.getMsg();
	}
	vector<Film>::iterator it;
	for (it = allFilme.begin();it < allFilme.end();it++) {
		if ((*it).getTitlu() == titlu && (*it).getGen() == gen)
			return (*it);
	}
	throw RepoException("Nu exista film cu titlul " + titlu + " si genul " + gen + "\n");
}

const vector<Film>& Repository::getAll()
{
	try {
	srand((unsigned)time(0));
	int ran = (rand() % 10) + 1;
	if (ran <= prob)
		throw RepoException("random execp!!!!!!!!!!!!!!!!!!!!!!!!!!!");
}
	catch (RepoException& re) {
		cout << re.getMsg() << std::endl;
	}

	return this->allFilme;
}

void Repository::delete_film(string titlu)
{
	try {
	srand((unsigned)time(0));
	int ran = (rand() % 10) + 1;
	if (ran < prob)
		throw RepoException("random execp");
}
	catch (RepoException& re) {
		cout << re.getMsg();
	}
	//int i = 0;
	//Iterator<Film> it = allFilme.begin();
	//while (it.valid()) {
	//	if (it.element().getTitlu() == titlu) {
	//		this->allFilme.erase(i);
	//		break;
	//	}
	//	it.urmator();
	//	i++;
	//}
	//if (!it.valid())
	//	throw RepoException("Nu exista film cu titlul " + titlu + "\n");
	vector<Film>::iterator it;
	it = allFilme.begin();
		while (it != allFilme.end()) {
			if ((*it).getTitlu() == titlu) {
				allFilme.erase(it);
				return;
			}
				
			it++;
		}
		
		//if (it == allFilme.end());
		throw RepoException("Nu exista film cu titlul " + titlu + "\n");
}

void Repository::modify_film(string titlu, string new_tiltu, int new_an)
{
	try {
		srand((unsigned)time(0));
		int ran = (rand() % 10) + 1;
		if (ran < prob)
			throw RepoException("random execp");
	}
	catch (RepoException& re) {
		cout << re.getMsg();
	}
		//int i = 0;;
		//Iterator<Film> it = allFilme.begin();
	vector<Film>::iterator it;
	it = allFilme.begin();
		while (it!=allFilme.end()) {
			if ((*it).getTitlu() == titlu) {
				//this->allFilme.get(i).setTitlu(new_tiltu);
				//this->allFilme.get(i).setAn(new_an);
				(*it).setTitlu(new_tiltu);
				(*it).setAn(new_an);
				return;
			}
			it++;
		}


		throw RepoException("Nu exista film cu titlul " + titlu + "\n");
	
}


void repo_tests()
{
	 repo_test_add();
	 repo_test_find();
	 repo_test_modify();
	 repo_test_delete();
}

void repo_test_add()
{
	vector<Film> testv;
	Film f1;
	string titlu;
	titlu = "batman";
	f1.setTitlu(titlu);
	string gen = "drama";
	f1.setGen(gen);
	int an = 2002;
	f1.setAn(an);
	string actor = "Gion";
	f1.setActor(actor);
	Repository repo;
	repo.addFilm(f1);
	testv = repo.getAll();
	assert(testv.size() == 1);

}

void repo_test_find()
{
	Repository repo;
	Film f1;
	string titlu;
	titlu = "batman";
	f1.setTitlu(titlu);
	string gen = "drama";
	f1.setGen(gen);
	int an = 2002;
	f1.setAn(an);
	string actor = "Gion";
	f1.setActor(actor);
	try {
		Film f3 = repo.find(titlu);
	}
	catch (RepoException& re) {
		assert(true);
	}

	repo.addFilm(f1);
	Film f2 = repo.find(titlu);
	assert(f2.getTitlu() == f1.getTitlu());
	assert(repo.exista(f1) == true);
	Film f4;
	titlu = "Superman";
	gen = "comedie";
	an = 2006;
	actor = "Victor";
	f4.setActor(actor);
	f4.setGen(gen);
	f4.setAn(an);
	f4.setTitlu(titlu);
	repo.addFilm(f4);
	Film f5 = repo.find(titlu);
	assert(f5.getTitlu() == f4.getTitlu());
	titlu = "abcd";
	f5.setTitlu(titlu);

	repo.exista(f5);
	titlu = "Superman";
	Film f6 = repo.find2(titlu, gen);
	assert(f6.getTitlu() == f4.getTitlu());
	assert(f6.getGen() == f4.getGen());
}

void repo_test_delete() {
	vector<Film> testv;
	Film f1;
	string titlu;
	titlu = "batman";
	f1.setTitlu(titlu);
	string gen = "drama";
	f1.setGen(gen);
	int an = 2002;
	f1.setAn(an);
	string actor = "Gion";
	f1.setActor(actor);
	Repository repo;
	repo.addFilm(f1);


	Film f4;
	titlu = "Superman";
	gen = "comedie";
	an = 2006;
	actor = "Victor";
	f4.setActor(actor);
	f4.setGen(gen);
	f4.setAn(an);
	f4.setTitlu(titlu);
	repo.addFilm(f4);
	repo.delete_film(titlu);
	testv = repo.getAll();

	assert(testv.size() == 1);

	titlu = "abcd";
	try {
		repo.delete_film(titlu);
	}
	catch (RepoException) {
		assert(true);
	}

	assert(testv.size() == 1);
}

void repo_test_modify() {
	vector<Film> testv;
	Film f1;
	string titlu;
	titlu = "batman";
	f1.setTitlu(titlu);
	string gen = "drama";
	f1.setGen(gen);
	int an = 2002;
	f1.setAn(an);
	string actor = "Gion";
	f1.setActor(actor);
	Repository repo;
	repo.addFilm(f1);

	Film f4;
	titlu = "Superman";
	gen = "comedie";
	an = 2006;
	actor = "Victor";
	f4.setActor(actor);
	f4.setGen(gen);
	f4.setAn(an);
	f4.setTitlu(titlu);
	repo.addFilm(f4);
	string new_title = "abcddef";
	int new_an = 6;

	repo.modify_film(titlu, new_title, new_an);
	testv = repo.getAll();
	vector<Film>::iterator it=testv.begin();
	it++;
	assert((*it).getTitlu() == new_title);
	assert((*it).getAn() == new_an);

}

void RepositoryMap::addFilm(const Film& new_film)
{
	//if (exista(new_film))
	//	throw RepoException("Filmul cu titlul " + new_film.getTitlu() + " exista in memorie");
	//else
	this->allFilme.insert(std::pair<int,Film>(id,new_film));
	this->id++;

	srand((unsigned)time(0));
	int ran = (rand() % 10) + 1;
	if (ran < prob)
		throw RepoException("random execp");
}

bool RepositoryMap::exista(const Film& f)
{
	srand((unsigned)time(0));
	int ran = (rand() % 10) + 1;
	if (ran < prob)
		throw RepoException("random execp");
	try {
		find(f.getTitlu());
		return true;
	}
	catch (RepoException) {
		return false;
	}


}

const Film& RepositoryMap::find(string titlu)
{
	srand((unsigned)time(0));
	int ran = (rand() % 10) + 1;
	if (ran < prob)
		throw RepoException("random execp");
	//Iterator<Film> it = allFilme.begin();
	map<int,Film>::iterator it;
	it = allFilme.begin();
	if (allFilme.size() > 0) {
		while (it != allFilme.end()) {
			if ((*it).second.getTitlu() == titlu)
				return (*it).second;
			it++;
		}
		throw RepoException("Filmul cu titlul " + titlu + " nu exista in memorie \n");
	}
	throw RepoException("Filmul cu titlul " + titlu + " nu exista in memorie \n");

	
}

const Film& RepositoryMap::find2(string titlu, string gen)
{

	map<int, Film>::iterator it;
	it = allFilme.begin();
	while( it != allFilme.end()) {
		if ((*it).second.getTitlu() == titlu && (*it).second.getGen() == gen)
			return (*it).second;
		it++;
	} 
	srand((unsigned)time(0));
	int ran = (rand() % 10) + 1;
	if (ran < prob)
		throw RepoException("random execp");
	throw RepoException("Nu exista film cu titlul " + titlu + " si genul " + gen + "\n");
}

const vector<Film>& RepositoryMap::getAll()
{
	//return this->allFilme;
	srand((unsigned)time(0));
	int ran = (rand() % 10) + 1;
	if (ran < prob)
		throw RepoException("random execp");
	map<int, Film>::iterator it;
	
	vector<Film> allFilms;
	it = allFilme.begin();
	while (it != allFilme.end()) {
		allFilms.push_back((*it).second);
		it++;
	}
	return allFilms;
}

void RepositoryMap::delete_film(string titlu)
{

	map<int, Film>::iterator it;
	it = allFilme.begin();
	while (it != allFilme.end()) {
		if ((*it).second.getTitlu() == titlu) {
			allFilme.erase(it);
			return;
		}

		it++;
	}
	srand((unsigned)time(0));
	int ran = (rand() % 10) + 1;
	if (ran < prob)
		throw RepoException("random execp");
	//if (it == allFilme.end());
	throw RepoException("Nu exista film cu titlul " + titlu + "\n");
}

void RepositoryMap::modify_film(string titlu, string new_tiltu, int new_an)
{

	//int i = 0;;
	//Iterator<Film> it = allFilme.begin();
	map<int, Film>::iterator it;
	it = allFilme.begin();
	while (it != allFilme.end()) {
		if ((*it).second.getTitlu() == titlu) {
			//this->allFilme.get(i).setTitlu(new_tiltu);
			//this->allFilme.get(i).setAn(new_an);
			(*it).second.setTitlu(new_tiltu);
			(*it).second.setAn(new_an);
			return;
		}
		it++;
	}
	srand((unsigned)time(0));
	int ran = (rand() % 10) + 1;
	if (ran < prob)
		throw RepoException("random execp");

	throw RepoException("Nu exista film cu titlul " + titlu + "\n");

}