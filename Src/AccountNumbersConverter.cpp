#include "AccountNumbersConverter.h"
#include "Lexicon.h"
#include "StringUtils.h"

using namespace std;

#include <sstream>
#include <iostream>
#include <stdexcept>

AccountNumbersConverter::AccountNumbersConverter() {
}

AccountNumbersConverter::AccountNumbersConverter(const string ocrText) {
	read(ocrText);
}

StringList AccountNumbersConverter::read(const string ocrText) {
	_entries.clear();

	StringArray lines = toLines(ocrText);
	validateLines(lines);
	extractEntries(lines);
	return extractAccountNumbers();
}

OCREntryList AccountNumbersConverter::entries() const {
	return _entries;
}

StringArray AccountNumbersConverter::toLines(const string& text) const {
	StringArray lines;

	string str = rtrim(text, "\n\r");
	stringstream ss(str);
	string line;
	while(getline(ss, line, '\n')) {
		lines.push_back(line);
	}

	return lines;
}

OCRDataArray AccountNumbersConverter::extractEntries(const StringArray lines) {
	OCRDataArray entryArray;
	for (unsigned int i = 0; i < lines.size();) {
		entryArray.clear();

		for (unsigned int row=0; row < 4 && i < lines.size(); ++row, ++i) {
			entryArray.push_back(lines[i]);
		}
		_entries.push_back(OCREntry(entryArray));
	}

	return entryArray;
}

StringList AccountNumbersConverter::extractAccountNumbers() {
	_accountNumbers.clear();
	OCREntryListCIter iter;
	Lexicon lex;
	string accountNumber;
	OCREntry entry;

	for(iter = _entries.begin(); iter != _entries.end(); ++iter) {
		accountNumber = lex.parse((*iter));
		_accountNumbers.push_back(accountNumber);
	}

	return _accountNumbers;
}

StringList AccountNumbersConverter::accountNumbers() const {
	return _accountNumbers;
}

void AccountNumbersConverter::validateLines(StringArray const lines) {
    if (lines.size() == 0) {
    	throw invalid_argument("The file is empty!");
    }
}
