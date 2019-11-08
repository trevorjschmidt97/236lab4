#include "relation.h"

void relation::select1(int index, string input) { 
	set<Tuple> newTupleSet;

        for (auto t : tupleSet) {
        	if (t.at(index) == input) {
                   	newTupleSet.insert(t);
                }
      	}

     	tupleSet = newTupleSet;
}

void relation::select2(int index, int index2) {
     	set<Tuple> newTupleSet;

      	for (auto t : tupleSet) {
           	if (t.at(index) == t.at(index2)) {
                      	newTupleSet.insert(t);
            	}
      	}

	tupleSet = newTupleSet;
}

void relation::project(map<string, int> mapp, vector<string> stringVector) {
  	set<Tuple> newTupleSet;

    	for (auto t : tupleSet) {
           	Tuple newTuple;
            	for (unsigned int i = 0; i < stringVector.size(); ++i) {
                  	newTuple.push_back(t.at(mapp.at(stringVector.at(i))));
            	}
            	if (newTuple.size() != 0) {
                	newTupleSet.insert(newTuple);
              	}
   	}
     	tupleSet = newTupleSet;
}

void relation::addTuple(vector<string> inputVector) {
   	Tuple t;

     	for (unsigned int i = 0; i < inputVector.size(); ++i) {
             	t.push_back(inputVector.at(i));
    	}

     	tupleSet.insert(t);
}

void relation::toString() {
  	if (tupleSet.size() != 0) {
           	for (auto t : tupleSet) {
                   	cout << "  ";
                     	cout << attributeNames.at(0) << "=" << t.at(0);
                     	for (unsigned int j = 1; j < attributeNames.size(); ++j) {
                          	cout << ", " << attributeNames.at(j) << "=" << t.at(j);
                    	}
                      	cout << endl;
             	}
      	}
}

