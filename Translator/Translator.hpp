#ifndef TRANSLATOR_DEF
#define	TRANSLATOR_DEF

#include <iostream>
#include <map>
#include <string>
#include <exceptions>
#include <Operator.hpp>

class Translator{
	std::map<std::string, operator> operations;

	public:
	Translator(std::istream& in) noexcept;

	int32_t translate(const std::string& operation) const noexcept;
};

#endif
