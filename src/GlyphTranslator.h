#pragma once
#include "../Src/glyph.h";

class GlyphTranslator {
public:
	GlyphTranslator();
	GlyphTranslator(const OCRDataArray&entries);
	virtual ~GlyphTranslator() {};

	virtual void SetEntries(OCRDataArray const entries);

	virtual std::string GetValues();

private:
	std::string _values;
};
