#pragma once

#include "../../Src/OCRData.h"

class ConcreteOCRData : public OCRData {
public:
	ConcreteOCRData(OCRDataArray const dataArray);
	virtual ~ConcreteOCRData() {};
};
