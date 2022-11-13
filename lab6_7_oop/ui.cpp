#include "ui.h"
#include <iostream>
using namespace std;
void ui::print_menu()
{
	cout << "-Meniu magazin-" << endl;
	cout << "1. Adauga filme noi" << std::endl;
	cout << "2. Afiseaza filmele" << std::endl;
	cout << "3. Cauta film" << std::endl;
	cout << "4. Sterge filme" << std::endl;
	cout << "5. Modifica filme" << std::endl;
	cout << "6. Filtrare" << std::endl;
	cout << "7. Sortare" << std::endl;
	cout << "8. Meniu cos " << std::endl;
	cout << "9. Iesi" << endl;
	cout << "10. Fisier" << endl;
	cout << "11. Undo" << endl;
}

void ui::add_menu()
{
	string titlu, gen, actor;
	int an_apar;
	
	cout << "Introduceti titlul:";
	getline(cin >> ws, titlu);
	
	cout << "Introduceti genul filmului:";
	getline(cin >> ws, gen);
	
	cout << "Introduceti anul aparitiei:";
	cin >>  an_apar;
	
	cout << "Introduceti numele actorului principal:";
	getline(cin >> ws, actor);

	try {
		serv.addFilm(titlu, gen, an_apar, actor);
	}
	catch (RepoException& re) {
		cout << re.getMsg();
	}
	catch (ValidationException& ve) {
		cout << ve.getErr();
	}
		

}

void ui::find_menu()
{
	string titlu;
	
	cout << "Introduceti titlul filmului cautat:";
	getline(cin >> ws, titlu);
	try {
		 const Film& found=serv.find(titlu);
		 cout << "Titlu: " << found.getTitlu() << " Gen: " << found.getGen() << " Anul aparitiei: " << found.getAn() << "Actor principal: " << found.getActor() << endl;
	}
	catch (RepoException& re) {
		cout << re.getMsg();
	}
}

void ui::delete_menu()
{
	string titlu;

	cout << "Introduceti titlul filmului pentru stergere:";
	getline(cin >> ws, titlu);
	try {
		serv.delete_film(titlu);
		
	}
	catch (RepoException& re) {
		cout << re.getMsg();
	}
}

void ui::modify_menu()
{
	string titlu,new_title;
	int new_an;
	cout << "Introduceti titlul filmului pentru modificare:";
	getline(cin >> ws, titlu);
	cout << "Introduceti noul titlu:";
	getline(cin >> ws, new_title);
	cout << "Introduceti noul an:";
	cin >> new_an;

	try {
		serv.modify_film(titlu, new_title, new_an);

	}
	catch (RepoException& re) {
		cout << re.getMsg();
	}
}

void ui::show_all()
{
	vector<Film> cop = serv.getFilme();
	//Iterator<Film> it = cop.begin();
	vector<Film>::iterator it;
	for(it=cop.begin();it<cop.end();it++)
			cout << "Titlu: " << (*it).getTitlu() << " Gen: " << (*it).getGen() << " Anul aparitiei: " << (*it).getAn() << " Actor principal: " << (*it).getActor() << endl;

	


}

void ui::filter_menu()
{
	cout << "Alegeti dupa ce foriti sa filtrati :" << std::endl;
	cout << "		1.Titlu" << std::endl;
	cout << "		2.Anul aparitiei" << std::endl;
	int option;
	cin >> option;
	if (option == 1) {
		cout << "Introduceti titlul cautat: " ;
		string titlu_cautat;
		getline(cin >> ws, titlu_cautat);
		cout << std::endl;
		vector<Film> vect = serv.filter_by_titlu(titlu_cautat);
		if (vect.size() > 0) {
			//Iterator<Film> it = vect.begin();
			vector<Film>::iterator it;
			for (it = vect.begin();it < vect.end();it++)
				cout << "Titlu: " << (*it).getTitlu() << " Gen: " << (*it).getGen() << " Anul aparitiei: " << (*it).getAn() << " Actor principal: " << (*it).getActor() << endl;

		}
		else {
			cout << "Nu exista filme cu titlul introdus" << std::endl;
		}
	}
	else if (option == 2) {
		cout << "Introduceti anul cautat: " ;
		int an_cautat;
		cin >> an_cautat;
		cout << std::endl;
		vector<Film> vect = serv.filter_by_an(an_cautat);
		if (vect.size() > 0) {
			//Iterator<Film> it = vect.begin();
			vector<Film>::iterator it;
			for (it = vect.begin();it < vect.end();it++)
				cout << "Titlu: " << (*it).getTitlu() << " Gen: " << (*it).getGen() << " Anul aparitiei: " << (*it).getAn() << " Actor principal: " << (*it).getActor() << endl;

		}
		else {
			cout << "Nu exista filme cu anul introdus" << std::endl;
		}
	}
	else
		cout << "Optiune invalida!!!" << std::endl;
}

void ui::sort_ui()
{

	cout << "Alegeti dupa ce dorii sa sortati :" << std::endl;
	cout << "1. Actor" << std::endl;
	cout << "2. Anul aparitiei" << std::endl;
	cout << "3. Titlu" << std::endl;
	cout << "Introduceti optiunea dumneavoastra: ";
	int option;
	cin >> option;
	cout << std::endl;
	vector<Film> vect1;
	switch (option)
	{	
	case 1:
		vect1=serv.sortActor();
		break;
	case 2:
		vect1 = serv.sortAn();
		break;
	case 3:
		vect1 = serv.sortTitlu();
		break;
	default:
		break;
	}
	if (vect1.size() > 0) {
		//Iterator<Film> it = vect1.begin();
		vector<Film>::iterator it;
		for (it = vect1.begin();it < vect1.end();it++)
			cout << "Titlu: " << (*it).getTitlu() << " Gen: " << (*it).getGen() << " Anul aparitiei: " << (*it).getAn() << " Actor principal: " << (*it).getActor() << endl;
		
	}
	else {
		cout << "Nu exista filme cu anul " << std::endl;
	}
}
void ui::cos_menu()
{	cout << " -Meniu cos-" << endl;
	cout << "1. Adauga film nou in cos" << endl;
	cout << "2. Vizualizare cos" << endl;
	cout << "3. Genereaza filme in cos" << endl;
	cout << "4. Goleste cosul" << endl;
	cout << "5. Inapoi" << endl;
}

void ui::add_2_cos()
{
	string titlu, gen;
	cout << "Introduceti titlul filmului ce vreti sa il adaugati: ";
	getline(cin >> ws ,titlu);
	cout << "Introduceti genul filmului ce doriti sa il adaugati: ";
	getline(cin >> ws, gen);
	try {
		serv.addFilmToCos(titlu, gen);
		cout << "Film adaugat cu succes "<<endl;
	}
	catch (RepoException& re) {
		cout<<re.getMsg();
	}

}
void ui::show_cos()
{
	vector<Film> filme_cos=serv.getCos();
	for (const auto& film : filme_cos) {
		cout << "Titlu: " << film.getTitlu() << " Gen: " << film.getGen() << " Anul aparitiei: " << film.getAn() << " Actor principal: " << film.getActor() << endl;
	}
}

void ui:: addRandomToCos() {
	cout << "Introduceti cate filme doriti sa adaugati: ";
	int cant;
	cin >> cant;
	try {
		int added = serv.addRandom(cant);
		cout << "S-au adaugat " << added << " filme"<<endl;
	}
	catch (RepoException& re) {
		cout << re.getMsg();
	}

}

void ui::Cos_ui()
{
	int run = 1;
	int x,option;
	while (run) {
		cos_menu();
		cout << "Optiunea dumneavoastra este:";
		cin >> option;
		switch (option)
		{ 
		case 1:
			add_2_cos();
			break;
		case 2:
			show_cos();
			break;
		case 3:
			addRandomToCos();
			break;
		case 4:
			serv.clearCos();
			cout << "Cosul a fost golit" << endl;
			break;
		case 5:
			run = 0;
			break;
		default:
			break;
		}
		cout << "Exista "<< serv.getCos().size()<<" filme in cos" << endl;
	}
}
void ui::fis_ui()
{
	cout << "Introduceti numele fisierului: ";
	string filename;
	cin >> filename;
	serv.fis_cmd(filename);
}
void ui::test_all()
{
	testCreate();
	repo_tests();
	test_Service();
	test_validation();
	test_cos();
	test_undo_add();

}
void ui::undo_ui()
{
	cout << "1. Undo adaugare" << endl;
	cout << "2. Undo stergere" << endl;
	cout << "3. Undo modificare" << endl;
	cout << "Optiunea dumneavoastra este: ";
	int option;
	cin >> option;
	switch (option)
	{
	case 1:
		serv.addUndo.doUndo();
		break;
	case 2:
		serv.delUndo.doUndo();
		break;
	case 3:
		serv.modUndo.doUndo();
		break;
	default:
		cout << "Optiune invalida !!!!" << endl;
		break;
	}
}
void ui::run()
{
	int run = 1;
	int x,option;
	while (run) {
		print_menu();
		cout << "Optiunea dumneavoastra este:";
/*		char cmd[3];
		x = scanf_s("%1s", cmd);
		if (x != 1) {
			printf("Optiune invalida!\n");
			option = 9;

		}
		else {
			cmd[2] = '\0';
			option = atoi(cmd);

		}*/	
		cin >> option;
		switch (option) {
		case 1:
			add_menu();
			break;
		case 2:
			show_all();
			break;
		case 3:
			find_menu();
			break;
		case 4:
			delete_menu();
			break;
		case 5:
			modify_menu();
			break;
		case 6:
			filter_menu();
			break;
		case 7:
			sort_ui();
			break;
		case 8:
			Cos_ui();
			break;
		case 9:
			run = 0;
			break;
		case 10:
			fis_ui();
			break;
		case 11:
			undo_ui();
			break;
		}
		
	}
}


