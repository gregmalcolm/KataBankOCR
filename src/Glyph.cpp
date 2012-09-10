#include "Glyph.h"
#include <stdexcept>
#include <tr1/memory>

using namespace std;

typedef tr1::shared_ptr<const OCREntries> OCREntriesConstPtr;

Glyph::Glyph(){
}

Glyph::Glyph(OCRDataArray const dataArray)
: super(dataArray) {
	LocalValidate();
}

bool Glyph::MatchBackOfOCREntries(const OCREntries entries) {
	string glyphStr = toString();
    string entriesStr = toString(entries.toArray());

    return glyphStr.compare(entriesStr) == 0;
}

bool Glyph::MatchBackOfOCREntries(const OCREntries entries,
		                          OCREntries& remainder) {
	bool isMatch = MatchBackOfOCREntries(entries);
    remainder.SetData(entries);
    return isMatch;
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
