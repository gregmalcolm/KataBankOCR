#include "OCRData.h"
#include <stdexcept>

using namespace std;

OCRData::OCRData() {
}

OCRData::OCRData(OCRDataArray const dataArray)
  : _dataArray(dataArray) {
    localValidate();
}

void OCRData::setData(const IOCRData& data) {
	_dataArray = data.toArray();
	validate();
}

OCRDataArray OCRData::toArray() const {
    return getData();
}

unsigned int OCRData::height() const {
    return getData().size();
}

unsigned int OCRData::width() const {
	if (height() == 0) {
		return 0;
	} else {
		return getData()[0].size();
	}
}

void OCRData::validate() const {
	localValidate();
}

void OCRData::localValidate() const {
    if (height() != 4) {
    	throw invalid_argument("The height is supposed to be 4 characters");
    }

    for( unsigned int i = 1; i < height(); ++i) {
        if (getData().at(i).size() != width()) {
            throw invalid_argument("The data rows should all be the same width");
        }
    }
}

OCRDataArray OCRData::getData() const {
    return _dataArray;
}

