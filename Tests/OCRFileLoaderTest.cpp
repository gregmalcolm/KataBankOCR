#include "../Src/OCRFileLoader.h"
#include "../Src/StringUtils.h"

#include <CppUTest/TestHarness.h>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

TEST_GROUP(OCRFileLoader) {

};

TEST(OCRFileLoader,
	 when_the_file_is_loaded_then_the_account_number_are_available) {

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

	OCRFileLoader ocr("ocr_data1.in");
	StringList numbers = ocr.accountNumbers();
	CHECK_EQUAL(0, numbers.front().compare("987654321"));

	remove("ocr_data1.in");
 }
