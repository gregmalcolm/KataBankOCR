#include "OCREntries.h"

using namespace std;

OCREntries::OCREntries() {
}

OCREntries::OCREntries(OCRDataArray const dataArray)
  : super(dataArray) {
}

OCREntries OCREntries::chopFromBack(const unsigned int columns) {
	OCRDataArray arr(toArray());
	OCRDataArrayIter iter;
    for( iter = arr.begin(); iter < arr.end(); ++iter ) {
        (*iter).erase(0, columns);
    }
    return OCREntries(arr);
}
