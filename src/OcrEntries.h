#pragma once
#include <iostream>
#include <vector>
#include <string>

typedef std::vector<std::string> OcrEntriesArray;

class OcrEntries {
public:
	OcrEntries(OcrEntriesArray const entriesArray);
	virtual ~OcrEntries();

	virtual OcrEntriesArray toArray() const;
	virtual int Height() const;

private:
	OcrEntriesArray _entriesArray;
};

