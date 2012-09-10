#include "OCRData.h"
#include <stdexcept>

using namespace std;

OCRData::OCRData(OCRDataArray const dataArray)
  : _dataArray(dataArray) {
    LocalValidate();
}

OCRDataArray OCRData::toArray() const {
    return getData();
}

unsigned int OCRData::Height() const {
    return getData().size();
}

unsigned int OCRData::Width() const {
    return getData()[0].size();
}

void OCRData::Validate() const {
	LocalValidate();
}

void OCRData::LocalValidate() const {
    if (Height() != 4) {
    	throw invalid_argument("The height is supposed to be 4 characters");
    }

    for( unsigned int i = 1; i < Height(); ++i) {
        if (getData().at(i).size() != Width()) {
            throw invalid_argument("The data rows should all be the same width");
        }
    }
}

OCRDataArray OCRData::getData() const {
    return _dataArray;
}

