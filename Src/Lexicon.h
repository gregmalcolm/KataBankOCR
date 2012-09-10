#pragma once

#include "Glyph.h"

#include <list>

typedef std::list<Glyph> GlyphList;
typedef GlyphList::const_iterator GlyphListCIter;
typedef GlyphList::iterator GlyphListIter;

class Lexicon {
public:
	Lexicon();
	virtual ~Lexicon() {};

	virtual std::string parse(OCREntries const & entries, std::string values = "");

private:
	GlyphList _glyphs;
};
