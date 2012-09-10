#include "Glyph.h"

using namespace std;

Glyph::Glyph(OCRDataArray const dataArray)
: OCRData(dataArray) {
}

bool Glyph::MatchBackOfOCREntries(const OCRDataArray entries) {
    string glyphStr = toString();
    string entriesStr = toString(entries);
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
