#include "../Src/Lexicon.h"

#include <CppUTest/TestHarness.h>
#include <iostream>

TEST_GROUP(Lexicon) {
	Lexicon lexicon;
};

TEST(Lexicon, when_the_entries_contains_numbers_0_through_8) {
    std::string arr[] = { " _     _  _     _  _  _  _ ",
                          "| |  | _| _||_||_ |_   ||_|",
                          "|_|  ||_  _|  | _||_|  ||_|",
                          "                           "};
    OCRDataArray data(arr, arr + 4);
    OCREntries entries(data);
    std::string values(lexicon.parse(entries));

    CHECK_EQUAL(0, values.compare("012345678"));
}

TEST(Lexicon, when_the_entries_contains_numbers_9_through_1) {
    std::string arr[] = { " _  _  _  _  _     _  _    ",
                          "|_||_|  ||_ |_ |_| _| _|  |",
                          " _||_|  ||_| _|  | _||_   |",
                          "                           "};
    OCRDataArray data(arr, arr + 4);
    OCREntries entries(data);
    std::string values(lexicon.parse(entries));

    CHECK_EQUAL(0, values.compare("987654321"));
}
