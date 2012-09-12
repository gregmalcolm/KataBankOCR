#pragma once

#include "OCREntry.h"

class Glyph : public OCRData {
public:
	typedef OCRData super;

    Glyph();
    Glyph(OCRDataArray const dataArray, const std::string value);
    virtual ~Glyph() {};

    virtual bool matchBackOfOCREntry(const OCREntry entry);
    virtual bool matchBackOfOCREntry(OCREntry entry,
    		                           OCREntry& remainder);
    virtual void validate() const;

    virtual std::string getValue() const;
    virtual void setValue(std::string value);

private:
    void localValidate() const;
    std::string toString() const;
    std::string toString(const OCRDataArray entry) const;

private:
    std::string _value;
};
