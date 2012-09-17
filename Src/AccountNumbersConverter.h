#pragma once

#include "StringUtils.h"
#include "IntUtils.h"
#include "../Src/OCREntry.h"

#include <string>
#include <list>

struct Account {
	std::string number;
};

typedef std::list<Account>        AccountList;
typedef AccountList::iterator       AccountListIter;
typedef AccountList::const_iterator AccountListCIter;

class AccountNumbersConverter {
public:
	AccountNumbersConverter();
	AccountNumbersConverter(const std::string ocrText);
	virtual ~AccountNumbersConverter() {};

	virtual AccountList  read(const std::string ocrText);
	virtual OCREntryList entries() const;
	virtual AccountList  accounts() const;
	virtual IntList      checksums() const;

private:
	void         validateLines(StringArray const lines);
	StringArray  toLines(const std::string& text) const;
	OCRDataArray extractEntries(const StringArray lines);
	int          extractChecksum(const std::string line);
	AccountList  extractAccounts();
	StringList   extractAccountNumbers();

private:
	OCREntryList _entries;
	AccountList  _accounts;
};
