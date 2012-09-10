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
	virtual int Height() const;
	virtual int Width() const;
	virtual void Validate() const;

protected:
	OCRDataArray getData() const;

private:
	OCRDataArray _dataArray;
};
