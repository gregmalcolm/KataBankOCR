#pragma once

#include <string>

class ChecksumCalculator {
public:
	unsigned int checksumFor(const std::string accountNumber) const;

private:
	unsigned int digitValue(const std::string accountNumber,
			                const unsigned int index) const;

	unsigned int digitModifier(const std::string accountNumber,
			                   const unsigned int index) const;
};
