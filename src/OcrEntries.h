#pragma once

#include "OCRData.h"

class OCREntries : public OCRData {
public:
	typedef OCRData super;

    OCREntries();
    OCREntries(OCRDataArray const dataArray);
    virtual ~OCREntries() {};

    virtual void validate() const;
    virtual OCREntries chopFromBack(const unsigned int columns = 3);
private:
    void localValidate() const;
};

