#include "Cos.h"

void Cos::addFilmToC(const Film& f)
{
	this->CosFilme.push_back(f);
}

void Cos::clearCos()
{
	this->CosFilme.clear();
}

void Cos::generateCos(vector<Film> allFilme, int cant)
{
	std::shuffle(allFilme.begin(), allFilme.end(), std::default_random_engine(std::random_device{}()));
	while (CosFilme.size() < cant && allFilme.size() > 0) {
		CosFilme.push_back(allFilme.back());
		allFilme.pop_back();
	}
}

vector<Film>& Cos::getCos()
{
	return this->CosFilme;
}

void test_cos() {
	Cos cos;
	string titlu;
	titlu = "batman";
	string gen = "drama";
	int an = 2002;
	string actor = "Gion";
	Film f{titlu,gen,an,actor};
	cos.addFilmToC(f);
	vector<Film> vect;
	vect = cos.getCos();
	assert(vect.size() == 1);
	cos.clearCos();
	vect = cos.getCos();
	assert(vect.size() == 0);
	test_genereate();
}

void test_genereate() {
	Cos cos;
	string titlu;
	titlu = "batman";
	string gen = "drama";
	int an = 2002;
	string actor = "Gion";
	Film f{ titlu,gen,an,actor };
	vector<Film> vect;
	vect.push_back(f);
	titlu = "superman";
	gen = "comedie";
	an = 2009;
	actor = "eu";
	Film f1{ titlu,gen,an,actor };
	vect.push_back(f1);
	titlu = "ana";
	gen = "comedie";
	an = 2019;
	actor = "el";
	Film f2{ titlu,gen,an,actor };
	vect.push_back(f2);
	int cant = 2;
	cos.generateCos(vect, cant);
	vector<Film> test_v = cos.getCos();
	assert(test_v.size() == 2);
	cant = 3;
	cos.generateCos(vect, cant);
	test_v = cos.getCos();
	assert(test_v.size() == 3);
}