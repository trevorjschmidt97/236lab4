//
//  dataLog.h
//  dataLog
//
//  Created by Trevor Schmidt on 10/2/19.
//  Copyright © 2019 Trevor Schmidt. All rights reserved.
//



/*
 datalogProgram    ->    SCHEMES COLON scheme schemeList
                FACTS COLON factList
                RULES COLON ruleList
                QUERIES COLON query queryList

schemeList    ->    scheme schemeList | lambda
factList    ->    fact factList | lambda
ruleList    ->    rule ruleList | lambda
queryList    ->    query queryList | lambda

scheme       ->     ID LEFT_PAREN ID idList RIGHT_PAREN
fact        ->    ID LEFT_PAREN STRING stringList RIGHT_PAREN PERIOD
rule        ->    headPredicate COLON_DASH predicate predicateList PERIOD
query            ->      predicate Q_MARK

headPredicate    ->    ID LEFT_PAREN ID idList RIGHT_PAREN
predicate    ->    ID LEFT_PAREN parameter parameterList RIGHT_PAREN
    
predicateList    ->    COMMA predicate predicateList | lambda
parameterList    ->     COMMA parameter parameterList | lambda
stringList    ->     COMMA STRING stringList | lambda
idList      ->     COMMA ID idList | lambda

parameter    ->    STRING | ID | expression
expression    ->     LEFT_PAREN parameter operator parameter RIGHT_PAREN
operator    ->    ADD | MULTIPLY
*/

#ifndef dataLog_h
#define dataLog_h

#include <stdio.h>
#include <vector>
#include <iostream>
#include "token.h"
#include "predicate.h"
#include "rule.h"

using namespace std;

class dataLog
{
public:
	dataLog(void){};

	void executeDataLog()
	{
		datalogProgram();
	}

   	void setVect(vector <token*> vect)
   	{
		tokenVect = vect;
   	}


	vector <predicate*> getSchemeVect()
	{
		return schemeVect;
	}
	vector <predicate*> getFactVect()
	{
		return factVect;
	}
	vector <predicate*> getQuerieVect()
	{
		return querieVect;
	}
 

private:
   	vector <token*> tokenVect;
    	vector <predicate*> schemeVect;
    	vector <predicate*> factVect;
    	vector <predicate*> querieVect;
    	vector <predicate*> rulePredVect;
    	vector <rule*> ruleVect;
    	vector <string> domainVect;
    	vector <string> idListStrings;
    	vector <string> factListStrings;
    	vector <string> ruleListStrings;
    	vector <string> parameterStrings;

    	bool forexpression = false;
    	string expressionString = "";

    	void checkNPop(string);
    	void datalogProgram();
    	void schemeList();
    	void factList();
    	void ruleList();
    	void queryList();
    	void scheme();
    	void fact();
    	void ruleMethod();
    	void query();
    	predicate* headPredicate();
    	predicate* predicateMethod();
    	void predicateList();
    	void parameterList();
    	void stringList();
    	void idList();
    	void parameter();
    	void expression();
    	void operate();
};

#endif /* dataLog_h */
