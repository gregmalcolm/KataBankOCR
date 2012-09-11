#pragma once

#include "StringUtils.h"
#include "../Src/OCREntry.h"

#include <string>

class AccountNumbersConverter {
public:
	AccountNumbersConverter();
	AccountNumbersConverter(const std::string ocrText);
	virtual ~AccountNumbersConverter() {};

	virtual void read(const std::string ocrText);
	virtual OCREntryList entries() const;
	virtual StringList accountNumbers() const;

private:
	StringArray toLines(const std::string& text) const;
	OCRDataArray extractEntries(const StringArray lines);
	StringList extractAccountNumbers();

private:
	OCREntryList _entries;
	StringList _accountNumbers;
};
