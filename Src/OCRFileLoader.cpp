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
	_accounts = converter.accounts();
}

AccountList OCRFileLoader::accounts() const {
	return _accounts;
}

string OCRFileLoader::accountNumbersToString() {
	string text("");
	AccountListCIter iter;
	for(iter = _accounts.begin(); iter != _accounts.end(); ++iter ) {
		text += (*iter).number;
		text += "\n";
	}

	return text;
}
