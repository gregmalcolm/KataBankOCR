#include "OcrEntries.h"

OcrEntries::OcrEntries(OcrEntriesArray const entriesArray)
  : _entriesArray(entriesArray) {
}

OcrEntries::~OcrEntries() {
}

OcrEntriesArray OcrEntries::toArray() const {
	return _entriesArray;
}

int OcrEntries::Height() const {
	return _entriesArray.size();
}
