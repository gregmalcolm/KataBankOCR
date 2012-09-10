#pragma once

#include "OCREntries.h"

class Glyph : public OCRData {
public:
	typedef OCRData super;

    Glyph();
    Glyph(OCRDataArray const dataArray, const std::string value);
    virtual ~Glyph() {};

    virtual bool matchBackOfOCREntries(const OCREntries entries);
    virtual bool matchBackOfOCREntries(OCREntries entries,
    		                           OCREntries& remainder);
    virtual void validate() const;

    virtual std::string getValue() const;
    virtual void setValue(std::string value);

private:
    void localValidate() const;
    std::string toString() const;
    std::string toString(const OCRDataArray entries) const;

private:
    std::string _value;
};
