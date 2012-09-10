#include "GlyphTranslator.h"

GlyphTranslator::GlyphTranslator() : _values("") {
}

GlyphTranslator::GlyphTranslator(const OCRDataArray& entries) {
    SetEntries(entries);
}

void GlyphTranslator::SetEntries(OCRDataArray const entries) {
    if (entries[0].compare(" ") == 0) {
        _values += "1";
    } else {
        _values += "9";
    }
}

std::string GlyphTranslator::GetValues() {
    return _values;
}
