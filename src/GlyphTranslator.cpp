#include "GlyphTranslator.h"

GlyphTranslator::GlyphTranslator() : values("") {
}

GlyphTranslator::GlyphTranslator(const EntriesText& entries) {
	SetEntries(entries);
}

GlyphTranslator::~GlyphTranslator() {
}

void GlyphTranslator::SetEntries(EntriesText const entries) {
	if (entries[0].compare(" ") == 0) {
		values += "1";
	} else {
		values += "9";
	}
}

std::string GlyphTranslator::GetValues() {
	return values;
}
