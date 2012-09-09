#pragma once

#include "../src/OcrEntries.h"
#include <iostream>
#include <vector>
#include <string>

class Glyph {
public:
	Glyph(OcrEntriesArray const glyphArray);
	virtual ~Glyph();

	virtual bool MatchBackOfOcrEntries(const OcrEntriesArray entries);

	virtual void validate() const;
	virtual int Width() const;
	virtual int Height() const;

private:
	std::string toString() const;
	std::string toString(const OcrEntriesArray entries) const;

private:
	OcrEntriesArray _glyphArray;
};
