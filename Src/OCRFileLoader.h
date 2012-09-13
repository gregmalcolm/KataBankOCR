#pragma once

#include "StringUtils.h"

#include <string>

class OCRFileLoader {
public:
	OCRFileLoader();
	OCRFileLoader(std::string const inputFile);
	OCRFileLoader(std::string const inputFile, std::string const outputFile);
	virtual ~OCRFileLoader() {}

	virtual void open(std::string const inputFile);
	virtual void saveAccountNumbers(std::string const outputFile);

	virtual StringList accountNumbers() const;

private:
	void parse(std::string data);
	std::string accountNumbersToString();

private:
	StringList _accountNumbers;
};
