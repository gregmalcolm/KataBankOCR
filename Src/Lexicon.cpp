#include "Standard.h"
#include "Lexicon.h"
#include "LexiconBuilder.h"

using namespace std;

Lexicon::Lexicon() {
	LexiconBuilder builder;
	_glyphs = builder.build();
}

string Lexicon::parse(OCREntry const& entry) {
	return parse(entry, "");
}

string Lexicon::parse(OCREntry const& entry, string values) {
	bool isMatch = false;
	GlyphListIter iter;
	OCREntry remainder;

	for(iter = _glyphs.begin(); iter != _glyphs.end(); ++iter) {

		isMatch = (*iter).matchBackOfOCREntry( entry, remainder);
		if (isMatch) {
			values += (*iter).getValue();
			return values = parse(remainder, values);
		}
	}
	return values;
}



