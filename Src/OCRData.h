#pragma once

#include <iostream>
#include <vector>
#include <string>

typedef std::vector<std::string> OCRDataArray;

class IOCRData {
public:
	virtual ~IOCRData() {};

    virtual void SetData(const IOCRData& data) = 0;
    virtual OCRDataArray toArray() const = 0;
    virtual unsigned int Height() const = 0;
    virtual unsigned int Width() const = 0;
    virtual void Validate() const = 0;
};

class OCREntries;

class OCRData : public IOCRData {
public:
    OCRData();
    OCRData(OCRDataArray const dataArray);
    virtual ~OCRData() {};

    virtual void SetData(const IOCRData& data);
    virtual OCRDataArray toArray() const;
    virtual unsigned int Height() const;
    virtual unsigned int Width() const;
    virtual void Validate() const;

private:
    void LocalValidate() const;

protected:
    OCRDataArray getData() const;

private:
    OCRDataArray _dataArray;
};
