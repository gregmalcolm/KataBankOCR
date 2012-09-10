#pragma once

#include "OCREntries.h"

class Glyph : public OCRData {
public:
	typedef OCRData super;

    Glyph();
    Glyph(OCRDataArray const dataArray);
    virtual ~Glyph() {};

    virtual bool MatchBackOfOCREntries(const OCREntries entries);
    virtual bool MatchBackOfOCREntries(const OCREntries entries,
    		                           OCREntries& remainder);
    virtual void Validate() const;

private:
    void LocalValidate() const;

private:
    std::string toString() const;
    std::string toString(const OCRDataArray entries) const;
};
