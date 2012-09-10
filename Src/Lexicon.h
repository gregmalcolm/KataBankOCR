#pragma once

#include "Glyph.h"

#include <list>

typedef std::list<Glyph> GlyphList;

class Lexicon {
public:
	Lexicon();
	virtual ~Lexicon() {};
};
