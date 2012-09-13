#include "OCRFileLoader.h"
#include "AccountNumbersConverter.h"

#include <fstream>
#include <iostream>

using namespace std;

OCRFileLoader::OCRFileLoader() {
}

OCRFileLoader::OCRFileLoader(string const inputFile) {
	open(inputFile);
}

OCRFileLoader::OCRFileLoader(std::string const inputFile, std::string const outputFile) {
	open(inputFile);
	saveAccountNumbers(outputFile);
}

void OCRFileLoader::open(string const inputFile) {
	string data;
	string line;
	ifstream f;
	f.open(inputFile.c_str());
    while(!f.eof()) // To get you all the lines.
    {
        getline(f,line); // Saves the line in STRING.
        data += line;
        data += "\n";
    }

	f.close();

	parse(data);
}

void OCRFileLoader::saveAccountNumbers(string const inputFile) {
	string text = accountNumbersToString();

	ofstream f;
	f.open(inputFile.c_str());
	f << text;
	f.close();
}

void OCRFileLoader::parse(string data) {
	AccountNumbersConverter converter(data);
	_accountNumbers = converter.accountNumbers();
}

StringList OCRFileLoader::accountNumbers() const {
	return _accountNumbers;
}

string OCRFileLoader::accountNumbersToString() {
	string text("");
	StringListCIter iter;
	string number;
	for(iter = _accountNumbers.begin(); iter != _accountNumbers.end(); ++iter ) {
		number = (*iter);
		text += number;
		text += "\n";
	}

	return text;
}
