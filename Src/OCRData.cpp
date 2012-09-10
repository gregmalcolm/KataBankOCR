#include "OCRData.h"
#include <stdexcept>

using namespace std;

OCRData::OCRData(OCRDataArray const dataArray)
  : _dataArray(dataArray) {
	Validate();
}

OCRDataArray OCRData::toArray() const {
	return getData();
}

int OCRData::Height() const {
	return getData().size();
}

int OCRData::Width() const {
	return getData()[0].size();
}

void OCRData::Validate() const {
	if (Height() != 4) throw invalid_argument("The height is supposed to be 4 characters");
	if (Width() == 0)  throw invalid_argument("The width is supposed to be greater than one character");
}

OCRDataArray OCRData::getData() const {
	return _dataArray;
}

