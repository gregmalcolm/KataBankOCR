#pragma once
#include "../src/glyph.h";

class GlyphTranslator {
public:
	GlyphTranslator();
	GlyphTranslator(const OcrEntriesArray&entries);
	virtual ~GlyphTranslator();

	virtual void SetEntries(OcrEntriesArray const entries);

	virtual std::string GetValues();

private:
	std::string _values;
};
