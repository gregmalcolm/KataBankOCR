#pragma once

#include "Lexicon.h"

class Glyph;

class LexiconBuilder {
public:
	LexiconBuilder();
	virtual ~LexiconBuilder() {};

	virtual GlyphList build() const;

	virtual Glyph buildZeroGlyph() const;
	virtual Glyph buildOneGlyph() const;
	virtual Glyph buildTwoGlyph() const;
	virtual Glyph buildThreeGlyph() const;
	virtual Glyph buildFourGlyph() const;
	virtual Glyph buildFiveGlyph() const;
	virtual Glyph buildSixGlyph() const;
	virtual Glyph buildSevenGlyph() const;
	virtual Glyph buildEightGlyph() const;
	virtual Glyph buildNineGlyph() const;
	virtual Glyph buildSpaceGlyph() const;
};
