#pragma once
#include <string>
#include "Film.h"
#include "Repository.h"
#include <fstream>
using std::string;
class FileRepository:public Repository
{
private:
	string fileName;
	void load_from_file();
	void save_to_file();

public:
	FileRepository(string fileName) :Repository(), fileName{ fileName }{
		load_from_file();
	}

	void addFilm(const Film& f) override {
		Repository::addFilm(f);
		save_to_file();
	}

	void delete_film(string titlu) override {
		Repository::delete_film(titlu);
		save_to_file();
	}
};

