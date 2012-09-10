#include "OCRData.h"
#include <stdexcept>

using namespace std;

OCRData::OCRData() {
}

OCRData::OCRData(OCRDataArray const dataArray)
  : _dataArray(dataArray) {
    LocalValidate();
}

void OCRData::SetData(const IOCRData& data) {
	_dataArray = data.toArray();
	Validate();
}

OCRDataArray OCRData::toArray() const {
    return getData();
}

unsigned int OCRData::Height() const {
    return getData().size();
}

unsigned int OCRData::Width() const {
	if (Height() == 0) {
		return 0;
	} else {
		return getData()[0].size();
	}
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

