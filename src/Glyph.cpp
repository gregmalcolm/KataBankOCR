#include "Glyph.h"
#include <stdexcept>

using namespace std;

Glyph::Glyph(OCRDataArray const dataArray)
: super(dataArray) {
	LocalValidate();
}

bool Glyph::MatchBackOfOCREntries(const OCREntries entries) {
    string glyphStr = toString();
    string entriesStr = toString(entries.toArray());
    return glyphStr.compare(entriesStr) == 0;
}

string Glyph::toString() const {
    return toString(getData());
}

string Glyph::toString(const OCRDataArray entries) const {
    OCRDataArray::const_iterator iter;
    string str("");
    for( iter = entries.begin(); iter < entries.end(); ++iter ) {
        str += (*iter).substr(0, Width());
    }
    return str;
}

void Glyph::Validate() const {
	super::Validate();

	LocalValidate();
}
void Glyph::LocalValidate() const {
    if (Width() == 0) {
    	throw invalid_argument("The width is supposed to be greater than one character");
    }
}
