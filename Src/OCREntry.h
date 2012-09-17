#pragma once

#include "OCRData.h"

#include <list>

typedef std::list<OCREntry> OCREntryList;
typedef OCREntryList::iterator OCREntryListIter;
typedef OCREntryList::const_iterator OCREntryListCIter;

class OCREntry : public OCRData {
public:
	typedef OCRData super;
    static const int NO_CHECKSUM_SET = -1;

    OCREntry();
    OCREntry(OCRDataArray const dataArray);
    OCREntry(OCRDataArray const dataArray, const int checksum);
    virtual ~OCREntry() {};

    virtual void validate() const;
    virtual OCREntry chopFromBack(const unsigned int columns = 3);

    virtual void setChecksum(const int checksum);
    virtual int getChecksum() const;

private:
    void localValidate() const;

private:
    int _checksum;
};

