#pragma once

#include "AccountNumbersConverter.h";

#include <string>

class OCRFileLoader {
public:
	OCRFileLoader();
	OCRFileLoader(std::string const inputFile);
	OCRFileLoader(std::string const inputFile, std::string const outputFile);
	virtual ~OCRFileLoader() {}

	virtual void open(std::string const inputFile);
	virtual void saveAccountNumbers(std::string const outputFile);

	virtual AccountList accounts() const;

private:
	void parse(std::string data);
	std::string accountNumbersToString();

private:
	AccountList _accounts;
};
