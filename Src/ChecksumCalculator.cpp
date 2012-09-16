#include "ChecksumCalculator.h"

#include<iostream>
#include<sstream>

using namespace std;

unsigned int ChecksumCalculator::checksumFor(const string accountNumber) const {
	unsigned int checksum = 0;
	for (unsigned int i = 0; i < accountNumber.size(); ++i ) {
		checksum += ( digitValue(   accountNumber, i)
				  *   digitModifier(accountNumber, i) );
	}
	return (checksum % 11);
}

unsigned int ChecksumCalculator::digitValue(const string accountNumber,
		                                    const unsigned int index) const {
	return (accountNumber[index] - '0');
}

unsigned int ChecksumCalculator::digitModifier(const string accountNumber,
		                                       const unsigned int index) const {
	return (accountNumber.size() - index);
}
