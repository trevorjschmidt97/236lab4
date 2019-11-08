#ifndef interpreter_h
#define interpreter_h

#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include "database.h"
#include "dataLog.h"
#include "predicate.h"
#include "relation.h"

using namespace std;

class interpreter
{
public:
	interpreter(void){};

	void setSchemeVect(vector<predicate*> x) {
		this->schemeVect = x;
	}

	void setFactVect(vector<predicate*> x) {
		this->factVect = x;
	}

	void setQuerieVect(vector<predicate*> x) {
		this->querieVect = x;
	}

	relation interpretQuerie(predicate* querie);

	void executeInterpreter();
private:
	vector<predicate*> schemeVect;
	vector<predicate*> factVect;
	vector<predicate*> querieVect;

	database relationMap;

	bool success;
};

#endif //interpreter_h
