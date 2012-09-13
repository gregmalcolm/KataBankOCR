#include "../Src/OCRFileLoader.h"
#include "../Src/StringUtils.h"

#include <CppUTest/TestHarness.h>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

TEST_GROUP(OCRFileLoader) {
	void setup() {
		std::string data;
		data += " _  _  _  _  _     _  _    \n";
		data += "|_||_|  ||_ |_ |_| _| _|  |\n";
		data += " _||_|  ||_| _|  | _||_   |\n";
		data += "                           \n";
		data += " _     _  _     _  _  _  _ \n";
		data += "| |  | _||_||_||_ |_   ||_|\n";
		data += "|_|  ||_  _|  | _||_|  ||_|\n";
		data += "                           \n";

		std::ofstream ocrFile;
		ocrFile.open("ocr_data1.in");
		ocrFile << data;
		ocrFile.close();
	}

	void teardown() {
		remove("ocr_data1.in");
	}
};

TEST(OCRFileLoader,
	when_the_file_is_loaded_then_the_account_numbers_are_available) {

	OCRFileLoader ocr("ocr_data1.in");
	StringList numbers = ocr.accountNumbers();
	CHECK_EQUAL(0, numbers.front().compare("987654321"));
	CHECK_EQUAL(0,  numbers.back().compare("012945678"));
}

TEST(OCRFileLoader,
	when_the_file_is_loaded_then_the_accounts_numbers_can_be_dumped_to_another_file) {

	OCRFileLoader ocr("ocr_data1.in", "account_numbers1.out");

	std::string numbers;
	std::string line;
	std::ifstream f;
	f.open("account_numbers1.out");
    while(!f.eof()) // To get you all the lines.
    {
        getline(f, line); // Saves the line in STRING.
        numbers += line;
        numbers += "\n";
    }
    f.close();
    numbers = rtrim(numbers);

    remove("account_numbers1.out");

	CHECK_EQUAL(0, numbers.compare("987654321\n012945678"));
}
