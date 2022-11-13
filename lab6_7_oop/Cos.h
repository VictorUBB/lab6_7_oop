#pragma once
#include "Film.h"
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
using std::vector;

//Clasa ce se ocupa cu gestiunea produselor dintr-un cos
class Cos
{
private:
	//vectorul in care vom memeora filmele
	vector<Film> CosFilme;
public:
	//Constructor default
	Cos() = default;

	//functie de adaugare de noi filme
	void addFilmToC(const Film& f);

	//functie ce sterge toate filmele din memorie
	void clearCos();

	//Functie ce adauga un numar(cant) de filme random din vectorul allFilme in cos
	//allFilme- vectorul din care vor fi late filmele
	//cant- numarul de filme ce vrem sa il adaugam
	void generateCos(vector<Film> allFilme, int cant);

	//returnaza vectorul cu filme
	vector<Film>& getCos();
};

//teste
void test_cos();
void test_genereate();