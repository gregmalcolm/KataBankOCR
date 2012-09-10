#include "OCREntries.h"

using namespace std;

#include <stdexcept>

OCREntries::OCREntries() {
}

OCREntries::OCREntries(OCRDataArray const dataArray)
  : super(dataArray) {
	localValidate();
}

void OCREntries::validate() const {
	super::validate();

	localValidate();
}

OCREntries OCREntries::chopFromBack(const unsigned int columns) {
	OCRDataArray arr(toArray());
	OCRDataArrayIter iter;
    for( iter = arr.begin(); iter < arr.end(); ++iter ) {
        (*iter).erase(0, columns);
    }
    return OCREntries(arr);
}

void OCREntries::localValidate() const {
    if (width() > 27) {
    	throw invalid_argument("The width is supposed to be less than 27");
    }
}
