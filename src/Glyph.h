#pragma once
#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>

typedef std::vector<std::string> OcrEntriesText;

class Glyph {
public:
	Glyph(OcrEntriesText glyphText);
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
