#pragma once

#include "OCRData.h"

class OCREntries : public OCRData {
public:
	typedef OCRData super;

    OCREntries(OCRDataArray const dataArray);
    virtual ~OCREntries() {};
};

