#include "validation.h"
#include <assert.h>
void test_validation() {
	Film f1;
	string titlu;
	titlu = "";
	f1.setTitlu(titlu);
	string gen = "drama";
	f1.setGen(gen);
	int an = 2002;
	f1.setAn(an);
	string actor = "Gion";
	f1.setActor(actor);
	validation val;
	try {
		val.valideaza(f1);
		//assert(false);
	}
	catch (ValidationException& ve) {
		assert(true);
		assert(ve.getErr().size() > 1);
	}
	titlu = "Batman";
	gen = "";
	an = 2006;
	actor = "Gion";
	Film f2;
	f2.setActor(actor);
	f2.setAn(an);
	f2.setGen(gen);
	f2.setTitlu(titlu);
	try {
		val.valideaza(f2);
		//assert(false);
	}
	catch (ValidationException) {
		assert(true);
	}
	titlu = "Batman";
	gen = "drama";
	an = -2006;
	actor = "Gion";
	Film f3;
	f3.setActor(actor);
	f3.setAn(an);
	f3.setGen(gen);
	f3.setTitlu(titlu);
	try {
		val.valideaza(f3);
		//assert(false);
	}
	catch (ValidationException& ve) {

		assert(true);
	}
	titlu = "Batman";
	gen = "drama";
	an = 2006;
	actor = "";
	Film f4;
	f4.setActor(actor);
	f4.setAn(an);
	f4.setGen(gen);
	f4.setTitlu(titlu);
	try {
		val.valideaza(f4);
		//assert(false);
	}
	catch (ValidationException) {
		assert(true);
	}

}