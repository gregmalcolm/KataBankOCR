#pragma once

#include <iostream>
#include <vector>
#include <string>

typedef std::vector<std::string> OCRDataArray;
typedef OCRDataArray::const_iterator OCRDataArrayCIter;
typedef OCRDataArray::iterator OCRDataArrayIter;

class IOCRData {
public:
	virtual ~IOCRData() {};

    virtual void setData(const IOCRData& data) = 0;
    virtual void setData(const OCRDataArray& dataArray) = 0;
    virtual OCRDataArray toArray() const = 0;
    virtual unsigned int height() const = 0;
    virtual unsigned int width() const = 0;
    virtual void validate() const = 0;
};

class OCREntries;

class OCRData : public IOCRData {
public:
    OCRData();
    OCRData(OCRDataArray const dataArray);
    virtual ~OCRData() {};

    virtual void setData(const IOCRData& data);
    virtual void setData(const OCRDataArray& dataArray);
    virtual OCRDataArray toArray() const;
    virtual unsigned int height() const;
    virtual unsigned int width() const;
    virtual void validate() const;

private:
    void localValidate() const;

protected:
    OCRDataArray getData() const;

private:
    OCRDataArray _dataArray;
};
