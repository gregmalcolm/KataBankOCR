#include "Glyph.h"
#include <stdexcept>
#include <tr1/memory>

using namespace std;

typedef tr1::shared_ptr<const OCREntry> OCREntryConstPtr;

Glyph::Glyph(){
}

Glyph::Glyph(OCRDataArray const dataArray, const string value)
: super(dataArray), _value(value) {
	localValidate();
}

bool Glyph::matchBackOfOCREntry(const OCREntry entry) {
	string glyphStr = toString();
    string entryStr = toString(entry.toArray());

    return glyphStr.compare(entryStr) == 0;
}

bool Glyph::matchBackOfOCREntry(OCREntry entry,
		                          OCREntry& remainder) {
	bool isMatch = matchBackOfOCREntry(entry);
	if (isMatch) {
		OCREntry const& chopped = entry.chopFromBack(width());
		remainder.setData(chopped);
	}
	else {
		remainder.setData(entry);
	}
    return isMatch;
}

string Glyph::toString() const {
    return toString(getData());
}

string Glyph::toString(const OCRDataArray entry) const {
	OCRDataArrayCIter iter;
    string str("");
    for( iter = entry.begin(); iter < entry.end(); ++iter ) {
        str += (*iter).substr(0, width());
    }
    return str;
}

void Glyph::validate() const {
	super::validate();

	localValidate();
}

string Glyph::getValue() const {
	return _value;
}

void Glyph::setValue(std::string value) {
	_value = value;
}

void Glyph::localValidate() const {
    if (width() == 0) {
    	throw invalid_argument("The width is supposed to be greater than one character");
    }
}
