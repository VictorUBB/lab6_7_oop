#pragma once
#include "Film.h"
#include <vector>
#include <string>
using std::string;
using std::vector;
//#include "vectorDinamic.h"

class ValidationException {
	vector<string> errorMsg;
public:
	ValidationException(vector<string> errorMsg) :errorMsg{ errorMsg } {};

	string getErr() {
		//Iterator<string> it =errorMsg.begin();
		vector<string>::iterator it;
		it = errorMsg.begin();
		string msg = "";
		while (it!=errorMsg.end()){
			msg += (*it) + '\n';
			it++;
		}
		return msg;
	}
};

class validation
{
	
public:
	vector<string> errMsgs;
	void valideaza(const Film& f) {
		if (f.getTitlu().length() < 1)
			errMsgs.push_back("Titlul trebuie sa aiba cel putin un caracter");
		if(f.getGen().length()<1)
			errMsgs.push_back("Genul trebuie sa aiba cel putin un caracter");
		if(f.getActor().length()<1)
			errMsgs.push_back("Numele actorului trebuie sa aiba cel putin un caracter");
		if(f.getAn()<0)
			errMsgs.push_back("Anul aparitiei trebuie sa fie pozitiv");
		if (errMsgs.size() > 0)
			throw ValidationException(errMsgs);
	}
};

void test_validation();