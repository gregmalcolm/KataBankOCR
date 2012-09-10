#pragma once

#include "../../Src/OCRData.h"

class ConcreteOCRData : public OCRData {
public:
	typedef OCRData super;

    ConcreteOCRData();
    ConcreteOCRData(OCRDataArray const dataArray);
    virtual ~ConcreteOCRData() {};
};
