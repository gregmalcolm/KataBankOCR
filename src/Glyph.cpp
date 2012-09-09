#include "Glyph.h"

Glyph::Glyph(OcrEntriesText glyphText) : _glyphText(glyphText) {
	validate();
}

Glyph::~Glyph() {
}

bool Glyph::MatchFrontOfOcrEntries(const OcrEntriesText entries) {
//	glyphText = toString(_glyphText, Width())
	return true;
}

int Glyph::Width() const {
	return _glyphText[0].size();
}

int Glyph::Height() const {
	return _glyphText.size();
}

void Glyph::validate() const {
	if (Height() != 4) throw std::invalid_argument("The glyph height is supposed to be 4 characters");
	if (Width() == 0)  throw std::invalid_argument("The glyph width is supposed to be greater than one character");
}
