#pragma once
#include <iostream>
#include <vector>
#include <string>

typedef std::vector<std::string> OcrEntriesText;

class OcrEntries {
public:
	OcrEntries(OcrEntriesText const entriesText);
	virtual ~OcrEntries();

	virtual OcrEntriesText toArray() const;
	virtual int Height() const;

private:
	OcrEntriesText _entriesText;
};

