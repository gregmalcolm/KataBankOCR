#pragma once
#include "../src/glyph.h";

class GlyphTranslator {
public:
	GlyphTranslator();
	GlyphTranslator(const OcrEntriesText&entries);
	virtual ~GlyphTranslator();

	virtual void SetEntries(OcrEntriesText const entries);

	virtual std::string GetValues();

private:
	std::string _values;
};
