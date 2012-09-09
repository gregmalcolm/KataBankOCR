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

	virtual bool MatchFrontOfOcrEntries(const OcrEntriesText entries);

	virtual void validate() const;
	virtual int Width() const;
	virtual int Height() const;

private:
	OcrEntriesText _glyphText;
};
