#include <Translator.hpp>
#include <stringstream>
#include <vector>

using namespace std;

Translator::Translator(std::istream& in) noexcept{

}

int32_t Translator::translate(const string& operation) const noexcept{
	istringstream iss(operation);
	string nameOp;

	getline(iss, nameOp, ' ');
	Operator oper = operations.at(nameOp);

	vector<string> tokens;
	string tmp;
	while(getline(iss, tmp, ' ')
		tokens.push_back(tmp);

	return oper.translate(tokens);
}
