#ifndef OPERATOR_DEF
#define OPERATOR_DEF

#include <exceptions>
#include <vector>
#include <string>

class Operator{
	
	char** this_is_all;
	int* _sizeParts;
	int _numParts, _initiatedParts;

	public:
	Operator();
	~Operator();
	
	void addOperationCode(std::string oper) noexcept;
	void addDontCare(int size) noexcept;
	void addPart(int size) noexcept;

	int32_t translate(vector<std::string> parts) const noexcept;
};

#endif
