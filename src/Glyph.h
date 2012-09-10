#pragma once

#include "OCRData.h"

class Glyph : public OCRData {
public:
    Glyph(OCRDataArray const dataArray);
    virtual ~Glyph() {};

    virtual bool MatchBackOfOCREntries(const OCRDataArray entries);

private:
    std::string toString() const;
    std::string toString(const OCRDataArray entries) const;
};
