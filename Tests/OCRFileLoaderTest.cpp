#include "../Src/OCRFileLoader.h"
#include "../Src/StringUtils.h"

#include <CppUTest/TestHarness.h>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

TEST_GROUP(OCRFileLoader_given_the_input_file_has_2_entries) {
	std::string inputFilename;
	std::string outputFilename;

	void setup() {
		inputFilename =  "ocr_data.in";
		outputFilename = "account_numbers.in";

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
		ocrFile.open(inputFilename.c_str());
		ocrFile << data;
		ocrFile.close();
	}

	void teardown() {
		remove(inputFilename.c_str());
	}
};

TEST(OCRFileLoader_given_the_input_file_has_2_entries,
	               when_the_file_is_loaded_then_the_account_numbers_are_available) {

	OCRFileLoader ocr(inputFilename);
	StringList numbers = ocr.accountNumbers();
	CHECK_EQUAL(0, numbers.front().compare("987654321"));
	CHECK_EQUAL(0,  numbers.back().compare("012945678"));
}

TEST(OCRFileLoader_given_the_input_file_has_2_entries,
	               when_the_file_is_loaded_then_the_accounts_numbers_can_be_dumped_to_another_file) {

	OCRFileLoader ocr(inputFilename, outputFilename);

	std::string numbers;
	std::string line;
	std::ifstream f;
	f.open(outputFilename.c_str());
    while(!f.eof()) // To get you all the lines.
    {
        getline(f, line); // Saves the line in STRING.
        numbers += line;
        numbers += "\n";
    }
    f.close();
    numbers = rtrim(numbers);

    remove(outputFilename.c_str());

	CHECK_EQUAL(0, numbers.compare("987654321\n012945678"));
}

//////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////

TEST_GROUP(OCRFileLoader_given_there_are_1000_entries) {
	std::string inputFilename;
	std::string outputFilename;
	StringList numbers;

	void setup() {
		inputFilename =  "ocr_data2.in";
		outputFilename = "account_numbers2.in";

		std::ofstream ocrFile;
		ocrFile.open(inputFilename.c_str());
		for(unsigned int i = 0; i < 500; ++i) {
			std::string data;
			data += " _  _  _  _  _     _  _    \n";
			data += "|_||_|  ||_ | ||_| _| _|  |\n";
			data += "|_||_|  ||_||_|  | _||_   |\n";
			data += "                           \n";
			data += " _     _  _     _  _  _  _ \n";
			data += "| |  | _||_||_||_ |_   ||_|\n";
			data += "|_|  ||_  _|  | _||_|  ||_|\n";
			data += "                           \n";
			ocrFile << data;
		}

		ocrFile.close();

		OCRFileLoader ocr(inputFilename, outputFilename);

		std::string line;
		std::ifstream numbersFile;
		numbersFile.open(outputFilename.c_str());
	    while(!numbersFile.eof()) // To get you all the lines.
	    {
	        getline(numbersFile, line); // Saves the line in STRING.
	        if (line.size() > 0) {
	        	numbers.push_back(line);
	        }
	    }
	    numbersFile.close();

	    remove(inputFilename.c_str());
	    remove(outputFilename.c_str());
	}
};

// This test is turned off because its slow!
// It's more of an Acceptance Test really anyway...
IGNORE_TEST(OCRFileLoader_given_there_are_1000_entries,
		           then_1000_numbers_are_returned) {
	unsigned int size = numbers.size();
	CHECK_EQUAL(1000, size);
	CHECK_EQUAL(0, numbers.front().compare("887604321"));
	CHECK_EQUAL(0, numbers.back().compare( "012945678"));
}
