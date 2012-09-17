#pragma once

#include "StringUtils.h"
#include "../Src/OCREntry.h"

#include <string>

class AccountNumbersConverter {
public:
	AccountNumbersConverter();
	AccountNumbersConverter(const std::string ocrText);
	virtual ~AccountNumbersConverter() {};

	virtual StringList   read(const std::string ocrText);
	virtual OCREntryList entries() const;
	virtual StringList   accountNumbers() const;

private:
	void         validateLines(StringArray const lines);
	StringArray  toLines(const std::string& text) const;
	OCRDataArray extractEntries(const StringArray lines);
	int          extractChecksum(const std::string line);
	StringList   extractAccountNumbers();

private:
	OCREntryList _entries;
	StringList _accountNumbers;
};
