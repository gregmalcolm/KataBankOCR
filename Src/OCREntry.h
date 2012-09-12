#pragma once

#include "OCRData.h"

#include <list>

typedef std::list<OCREntry> OCREntryList;
typedef OCREntryList::iterator OCREntryListIter;
typedef OCREntryList::const_iterator OCREntryListCIter;

class OCREntry : public OCRData {
public:
	typedef OCRData super;

    OCREntry();
    OCREntry(OCRDataArray const dataArray);
    virtual ~OCREntry() {};

    virtual void validate() const;
    virtual OCREntry chopFromBack(const unsigned int columns = 3);
private:
    void localValidate() const;
};

