#pragma once
#include "Film.h"
#include "Repository.h"
#include <vector>

using std::vector;
class undo
{
	//vector<vector<Film>> undo_list;
public:
	virtual void doUndo() = 0;
	virtual ~undo() = default;
};

class UndoAdauga :public undo {
	Film adaugaFilm;
	RepositoryMain& repo;
	vector<Film> addList;
public:
	UndoAdauga(RepositoryMain& repo) :repo{ repo } {};
	void doUndo() override {
		repo.delete_film(adaugaFilm.getTitlu());
		addList.erase(addList.end() - 1);
	}
	void add_to_undo(Film f) {
		addList.push_back(f);
		adaugaFilm = f;
	}

};

class UndoSterge : public undo {
	Film stergeFilm;
	RepositoryMain& repo;
	vector<Film> deleteList;
public:
	UndoSterge(RepositoryMain& repo) :repo{ repo } {};
	void doUndo() override {
		repo.addFilm(stergeFilm);
		deleteList.erase(deleteList.end() - 1);
	}
	void add_to_del(Film f) {
		deleteList.push_back(f);
		stergeFilm = f;
	}
};

class UndoModifica : public undo {
	//Clasa pentru undo la modifiacari
	RepositoryMain& repo;
	typedef struct {
		string titlu_nou;
		string titlu;
		int an;
	}mod;
	//lista unde se tine titlul si anul inainte de modificari
	vector<mod> modList;
public:
	UndoModifica(RepositoryMain& repo) :repo{ repo } {};
	void doUndo() override {
		vector<mod>::iterator f;
		f = modList.end() - 1;
		repo.modify_film((*f).titlu_nou, (*f).titlu, (*f).an);
		modList.erase(modList.end() - 1);
	}
	void add_to_mod(string new_tiltu, string titlu, int new_an) {
		modList.push_back({ titlu, new_tiltu, new_an });

	}
};
