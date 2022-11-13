#include "FileRepository.h"

void FileRepository::load_from_file()
{
	std::ifstream f(fileName);
	if (!f.is_open())
		throw RepoException("Fisierul " + fileName + " nu poate fi deschis \n");
	while (!f.eof()) {
		string titlu, gen, actor;
		int an;
		f >> titlu;
		f >> gen;
		f >> an;
		f >> actor;
		if (f.eof()) {	//nu am reusit sa citesc numarul
			break;
		}
		Film f{ titlu,gen,an,actor };
		Repository::addFilm(f);
	}
	f.close();
}

void FileRepository::save_to_file()
{
	std::ofstream f(fileName);
	if (!f.is_open())
		throw RepoException("Fisierul " + fileName + " nu poate fi deschis \n");
	for (auto& film : getAll()) {
		f << film.getTitlu() <<std::endl;
		f << film.getGen() <<std::endl;
		f << film.getAn() << std::endl;
		f << film.getActor() << std::endl;

	}
	f.close();

}
