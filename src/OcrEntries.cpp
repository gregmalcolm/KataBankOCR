#include "OcrEntries.h"

OcrEntries::OcrEntries(OcrEntriesText const entriesText)
  : _entriesText(entriesText) {
}

OcrEntries::~OcrEntries() {
}

OcrEntriesText OcrEntries::toArray() const {
	return _entriesText;
}

int OcrEntries::Height() const {
	return _entriesText.size();
}
