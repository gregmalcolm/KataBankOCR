#include "../Src/AccountNumbersConverter.h"
#include "../Src/OCREntry.h"

#include <CppUTest/TestHarness.h>
#include <string>
#include <stdexcept>

TEST_GROUP(AccountNumbersConverter_given_data_is_loaded) {
	AccountNumbersConverter converter;

	void setup() {
		std::string data;
		data += " _     _  _     _  _  _  _ \n";
		data += "| |  | _| _||_||_ |_   ||_|\n";
		data += "|_|  ||_  _|  | _||_|  ||_|\n";
		data += "                           \n";
		data += " _  _  _  _  _     _  _    \n";
		data += "|_||_|  ||_ |_ |_| _| _|  |\n";
		data += " _||_|  ||_| _|  | _||_   |\n";
		data += "                           \n";
		data += "    _  _  _  _  _  _  _  _ \n";
		data += "|_||_ |_   ||_||_||_|  ||_ \n";
		data += "  | _||_|  ||_| _||_|  ||_|\n";
		data += "                           \n";
		data += " _     _  _        _  _  _ \n";
		data += "|_ |_| _| _|  ||_||_ |_   |\n";
		data += " _|  | _||_   |  | _||_|  |\n";
		data += "                           \n";

		converter.read(data);
	}
};

TEST(AccountNumbersConverter_given_data_is_loaded,
		                     then_the_entries_are_available_as_a_list) {
	OCREntryList entries(converter.entries());
	unsigned int size = entries.size();
	CHECK_EQUAL(4, size);
}

TEST(AccountNumbersConverter_given_data_is_loaded,
		                     then_the_first_entry_is_accessible) {
	OCREntryList entries(converter.entries());
	OCRDataArray lines = entries.front().toArray();
	CHECK_EQUAL(0, lines[0].compare(" _     _  _     _  _  _  _ "));
	CHECK_EQUAL(0, lines[1].compare("| |  | _| _||_||_ |_   ||_|"));
	CHECK_EQUAL(0, lines[2].compare("|_|  ||_  _|  | _||_|  ||_|"));
	CHECK_EQUAL(0, lines[3].compare("                           "));
}

TEST(AccountNumbersConverter_given_data_is_loaded,
		                     then_the_last_entry_is_accessible) {
	OCREntryList entries(converter.entries());
	OCRDataArray lines = entries.back().toArray();
	CHECK_EQUAL(0, lines[0].compare(" _     _  _        _  _  _ "));
	CHECK_EQUAL(0, lines[1].compare("|_ |_| _| _|  ||_||_ |_   |"));
	CHECK_EQUAL(0, lines[2].compare(" _|  | _||_   |  | _||_|  |"));
	CHECK_EQUAL(0, lines[3].compare("                           "));
}

TEST(AccountNumbersConverter_given_data_is_loaded,
		                     then_there_will_be_4_numbers_available) {
	StringList numbers = converter.accountNumbers();
	unsigned int size = numbers.size();
	CHECK_EQUAL(4, size);
}

TEST(AccountNumbersConverter_given_data_is_loaded,
		                     then_the_first_account_numbers_matches_the_ocr_entry) {
	StringList numbers = converter.accountNumbers();

	CHECK_EQUAL(0, numbers.front().compare("012345678"));
}

TEST(AccountNumbersConverter_given_data_is_loaded,
		                     then_the_last_account_numbers_matches_the_ocr_entry) {
	StringList numbers = converter.accountNumbers();

	CHECK_EQUAL(0, numbers.back().compare("543214567"));
}


/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////

TEST_GROUP(AccountNumbersConverter) {
};

TEST(AccountNumbersConverter,
	 when_the_file_is_empty_then_the_ocr_entries_has_a_size_of_zero) {

    bool ok = true;

    try {
    	AccountNumbersConverter converter("");
    } catch(std::invalid_argument& e) {
        ok = false;
    }

    CHECK_EQUAL(false, ok);
}


TEST(AccountNumbersConverter, when_read_is_called_then_it_returns_account_numbers) {
	std::string data;
	data += " _  _  _  _  _     _  _    \n";
	data += "|_||_|  ||_ |_ |_| _| _|  |\n";
	data += " _||_|  ||_| _|  | _||_   |\n";
	data += "                           \n";

	AccountNumbersConverter converter;
	StringList numbers = converter.read(data);

	CHECK_EQUAL(0, numbers.back().compare("987654321"));
}

TEST(AccountNumbersConverter,
	 when_the_number_of_lines_is_wrong_then_an_exception_is_thrown) {

    bool ok = true;

	std::string data;
	data += " _  _  _  _  _     _  _    \n";
	data += "|_||_|  ||_ |_ |_| _| _|  |\n";

    try {
    	AccountNumbersConverter converter(data);
    } catch(std::invalid_argument& e) {
        ok = false;
    }

    CHECK_EQUAL(false, ok);
}