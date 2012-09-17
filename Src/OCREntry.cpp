#include "OCREntry.h"
#include "ChecksumCalculator.h"

using namespace std;

#include <stdexcept>

OCREntry::OCREntry()
  : _checksum(NO_CHECKSUM_SET) {
}

OCREntry::OCREntry(OCRDataArray const dataArray)
  : super(dataArray), _checksum(NO_CHECKSUM_SET) {
	localValidate();
}

OCREntry::OCREntry(OCRDataArray const dataArray, const int checksum)
  : super(dataArray), _checksum(checksum) {
	localValidate();
}

void OCREntry::validate() const {
	super::validate();

	localValidate();
}

OCREntry OCREntry::chopFromBack(const unsigned int columns) {
	OCRDataArray arr(toArray());
	OCRDataArrayIter iter;
    for( iter = arr.begin(); iter < arr.end(); ++iter ) {
        (*iter).erase(0, columns);
    }
    return OCREntry(arr);
}

void OCREntry::setChecksum(const int checksum) {
	_checksum = checksum;
}

int OCREntry::getChecksum() const {
	return _checksum;
}

void OCREntry::localValidate() const {
    if (width() > 27) {
    	throw invalid_argument("The width is supposed to be less than 27");
    }
}
