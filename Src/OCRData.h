#pragma once

#include <iostream>
#include <vector>
#include <string>

typedef std::vector<std::string> OCRDataArray;

class OCRData {
public:
    OCRData(OCRDataArray const dataArray);
    virtual ~OCRData() {};

    virtual OCRDataArray toArray() const;
    virtual unsigned int Height() const;
    virtual unsigned int Width() const;
    virtual void Validate() const;

protected:
    OCRDataArray getData() const;

private:
    OCRDataArray _dataArray;
};
