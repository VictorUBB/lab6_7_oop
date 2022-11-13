#include "ui.h"

#include <crtdbg.h>
void start() {
	//;
	//cout << "Alegeti tipul repository:";
	int option;
	//std::cin >> option;
	option = 1;
	if (option == 1) {
		FileRepository repo{"filme.txt"};
		repo.prob = 5;
		validation val;
		Service srv{ repo,val };
		ui ui{ srv };
		ui.test_all();
		ui.run();
	}
	else {
		RepositoryMap repo;
		validation val;
		Service srv{ repo,val};
		ui ui{ srv };
		ui.test_all();
		ui.run();
	}
	//FileRepository filerepo{"filme.txt"};
	//validation val;
	//Service srv{ repo,val };
	//ui ui{ srv };
	//ui.test_all();
	//ui.run();
}

int main() {
	start();
	_CrtDumpMemoryLeaks();
}