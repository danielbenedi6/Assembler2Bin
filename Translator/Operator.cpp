//*******************************************************
// File: 
// Author: Daniel Benedí García
// Date: 
// Coms:
//*******************************************************

#include<Operator.hpp>

using namespace std;

Operator::Operator(int numParts){
	this_is_all = new char*[numParts];
	_numParts 	= numParts;
	_sizeParts	= new int[numParts];
	for(int i = 0; i < numParts; i++){
		_sizeParts[i] = 0;
	}
}

Operator::~Operator(){
	
	for(int i = 0; i < _numParts; i++){
		if(_sizeParts[i] != 0)
			delete[] this_is_all[i];
	}

	delete[] _sizeParts;
	delete[] this_is_all;
}



int32_t Operator::translate(vector<string> parts) const noexcept{
	int32_t out = 0;
	if(_initiatedParts != _numParts)
			throw runtime_error("Operation not constructed correctly");

	return ;
}
