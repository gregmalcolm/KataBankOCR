#include "OCREntry.h"

using namespace std;

#include <stdexcept>

OCREntry::OCREntry() {
}

OCREntry::OCREntry(OCRDataArray const dataArray)
  : super(dataArray) {
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

void OCREntry::localValidate() const {
    if (width() > 27) {
    	throw invalid_argument("The width is supposed to be less than 27");
    }
}
