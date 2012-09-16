#include <CppUTest/TestHarness.h>

#include "../Src/ChecksumCalculator.h"

TEST_GROUP(ChecksumCalculator) {
	ChecksumCalculator calculator;
};

TEST(ChecksumCalculator, when_account_number_is_345882865_then_checksum_is_0) {
	unsigned int checksum = calculator.checksumFor("345882865");
	CHECK_EQUAL(0, checksum);
}

TEST(ChecksumCalculator, when_account_number_is_5_then_checksum_is_5) {
	unsigned int checksum = calculator.checksumFor("5");
	CHECK_EQUAL(5, checksum);
}

TEST(ChecksumCalculator, when_account_number_is_000000000_then_checksum_is_0) {
	unsigned int checksum = calculator.checksumFor("000000000");
	CHECK_EQUAL(0, checksum);
}

TEST(ChecksumCalculator, when_account_number_is_987654321_then_checksum_is_10) {
	unsigned int checksum = calculator.checksumFor("987654321");
	CHECK_EQUAL(10, checksum);
}
