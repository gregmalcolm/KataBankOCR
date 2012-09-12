#pragma once

#include "StringUtils.h"

#include <string>

class OCRFileLoader {
public:
	OCRFileLoader();
	OCRFileLoader(std::string const inputFile);
	virtual ~OCRFileLoader() {}

	virtual void open(std::string const inputFile);

	virtual StringList accountNumbers() const;

private:
	void parse(std::string data);

private:
	StringList _accountNumbers;
};
