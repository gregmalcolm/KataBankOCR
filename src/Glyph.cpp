#include "Glyph.h"
#include <stdexcept>

using namespace std;

Glyph::Glyph(OcrEntriesText const glyphText) : _glyphText(glyphText) {
	validate();
}

Glyph::~Glyph() {
}

bool Glyph::MatchBackOfOcrEntries(const OcrEntriesText entries) {
	string glyphStr = toString();
	string entriesStr = toString(entries);
	return glyphStr.compare(entriesStr) == 0;
}

int Glyph::Width() const {
	return _glyphText[0].size();
}

int Glyph::Height() const {
	return _glyphText.size();
}

void Glyph::validate() const {
	if (Height() != 4) throw invalid_argument("The glyph height is supposed to be 4 characters");
	if (Width() == 0)  throw invalid_argument("The glyph width is supposed to be greater than one character");
}

string Glyph::toString() const {
	return toString(_glyphText);
}

string Glyph::toString(const OcrEntriesText entries) const {
	OcrEntriesText::const_iterator iter;
	string str("");
	for( iter = entries.begin(); iter < entries.end(); ++iter ) {
		str += (*iter).substr(0, Width());
	}
	return str;
}
