#pragma once
#include "../Src/Glyph.h";

class GlyphTranslator {
public:
    GlyphTranslator();
    GlyphTranslator(const OCRDataArray&entries);
    virtual ~GlyphTranslator() {};

    virtual void setEntries(OCRDataArray const entries);

    virtual std::string getValues();

private:
    std::string _values;
};
