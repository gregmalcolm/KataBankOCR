#include "Standard.h"
#include "Lexicon.h"
#include "LexiconBuilder.h"

using namespace std;

Lexicon::Lexicon() {
	LexiconBuilder builder;
	_glyphs = builder.build();
}

string Lexicon::parse(OCREntries const& entries, std::string values) {
	bool isMatch = false;
	GlyphListIter iter;
	OCREntries remainder;

	for(iter = _glyphs.begin(); iter != _glyphs.end(); ++iter) {

		isMatch = (*iter).matchBackOfOCREntries( entries, remainder);
		if (isMatch) {
			values += (*iter).getValue();
			return values = parse(remainder, values);
		}
	}
	return values;
}



