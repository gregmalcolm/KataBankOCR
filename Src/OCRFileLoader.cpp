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

void OCRFileLoader::parse(string data) {
	AccountNumbersConverter converter(data);
	_accountNumbers = converter.accountNumbers();
}

StringList OCRFileLoader::accountNumbers() const {
	return _accountNumbers;
}
