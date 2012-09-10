#pragma once

class Glyph;

class LexiconBuilder {
public:
	LexiconBuilder();
	virtual ~LexiconBuilder() {};

	virtual Glyph buildZeroGlyph();
};
