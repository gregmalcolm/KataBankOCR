#include "Glyph.h"
#include <stdexcept>
#include <tr1/memory>

using namespace std;

typedef tr1::shared_ptr<const OCREntries> OCREntriesConstPtr;

Glyph::Glyph(){
}

Glyph::Glyph(OCRDataArray const dataArray)
: super(dataArray) {
	localValidate();
}

bool Glyph::matchBackOfOCREntries(const OCREntries entries) {
	string glyphStr = toString();
    string entriesStr = toString(entries.toArray());

    return glyphStr.compare(entriesStr) == 0;
}

bool Glyph::matchBackOfOCREntries(OCREntries entries,
		                          OCREntries& remainder) {
	bool isMatch = matchBackOfOCREntries(entries);
	if (isMatch) {
		OCREntries const& chopped = entries.chopFromBack(width());
		remainder.setData(chopped);
	}
	else {
		remainder.setData(entries);
	}
    return isMatch;
}

string Glyph::toString() const {
    return toString(getData());
}

string Glyph::toString(const OCRDataArray entries) const {
	OCRDataArrayCIter iter;
    string str("");
    for( iter = entries.begin(); iter < entries.end(); ++iter ) {
        str += (*iter).substr(0, width());
    }
    return str;
}

void Glyph::validate() const {
	super::validate();

	localValidate();
}

void Glyph::localValidate() const {
    if (width() == 0) {
    	throw invalid_argument("The width is supposed to be greater than one character");
    }
}
