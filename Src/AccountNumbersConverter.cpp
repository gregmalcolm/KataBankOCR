#include "AccountNumbersConverter.h"
#include "ChecksumCalculator.h"
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

AccountList AccountNumbersConverter::read(const string ocrText) {
	_entries.clear();

	StringArray lines = toLines(ocrText);
	validateLines(lines);
	extractEntries(lines);
	return extractAccounts();
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
	OCREntry entry;
	int checksum = OCREntry::NO_CHECKSUM_SET;
	for (unsigned int lineNo = 0; lineNo < lines.size();) {
		entryArray.clear();


		for (unsigned int row=0; row < 5 && lineNo < lines.size(); ++row, ++lineNo) {
			if (row < 4) {
				entryArray.push_back(lines[lineNo]);
			} else {
			    checksum = extractChecksum(lines[lineNo]);
			}
		}

		entry = OCREntry(entryArray, checksum);

		_entries.push_back(entry);
	}

	return entryArray;
}

int AccountNumbersConverter::extractChecksum(const string line) {
	int checksum = OCREntry::NO_CHECKSUM_SET;

	istringstream ss(line);
	ss >> checksum;

	return checksum;
}

AccountList AccountNumbersConverter::extractAccounts() {
	_accounts.clear();
	OCREntryListCIter iter;
	Lexicon lex;
	Account account;
	ChecksumCalculator checksumCalc;
	int expectedChecksum;

	for(iter = _entries.begin(); iter != _entries.end(); ++iter) {
		account.number = lex.parse( (*iter) );

		expectedChecksum = checksumCalc.checksumFor(account.number);

		account.checksum = ( (*iter).getChecksum() );
		account.isErroneous = (expectedChecksum != account.checksum);
		account.displayText = account.number;
		if (account.isErroneous) {
			account.displayText += " ERR";
		}

		_accounts.push_back(account);
	}

	return _accounts;
}

AccountList AccountNumbersConverter::accounts() const {
	return _accounts;
}

void AccountNumbersConverter::validateLines(StringArray const lines) {
    if (lines.size() == 0) {
    	throw invalid_argument("The file is empty!");
    }
}
