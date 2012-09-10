#pragma once

#include "OCREntries.h"

class Glyph : public OCRData {
public:
	typedef OCRData super;

    Glyph();
    Glyph(OCRDataArray const dataArray);
    virtual ~Glyph() {};

    virtual bool matchBackOfOCREntries(const OCREntries entries);
    virtual bool matchBackOfOCREntries(const OCREntries entries,
    		                           OCREntries& remainder);
    virtual void validate() const;

private:
    void localValidate() const;

private:
    std::string toString() const;
    std::string toString(const OCRDataArray entries) const;
};
