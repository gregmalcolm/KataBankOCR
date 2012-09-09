#pragma once

#include "../src/OcrEntries.h"
#include <iostream>
#include <vector>
#include <string>

class Glyph {
public:
	Glyph(OcrEntriesText const glyphText);
	virtual ~Glyph();

	virtual bool MatchBackOfOcrEntries(const OcrEntriesText entries);

	virtual void validate() const;
	virtual int Width() const;
	virtual int Height() const;

private:
	std::string toString() const;
	std::string toString(const OcrEntriesText entries) const;

private:
	OcrEntriesText _glyphText;
};
