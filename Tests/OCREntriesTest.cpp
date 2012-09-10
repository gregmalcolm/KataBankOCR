#include "../Src/OCREntries.h"

#include <CppUTest/TestHarness.h>
#include <tr1/memory>
#include <stdexcept>

typedef std::tr1::shared_ptr<OCREntries> OCREntriesPtr;

TEST_GROUP(OCREntries_given_entries_text_of_5_6) {
    OCREntries entries;

    void setup() {
        std::string arr[] = { " _  _ ",
                              "|_ |_ ",
                              " _||_|",
                              "      "};
        OCRDataArray entriesArray(arr, arr + 4);
        entries.setData(entriesArray);
    }
};

TEST(OCREntries_given_entries_text_of_5_6,
                when_chopping_from_back_then_3_columns_will_be_removed) {
	OCREntries reducedEntries(entries.chopFromBack());

    CHECK(reducedEntries.toArray()[0].compare(" _ ") == 0);
    CHECK(reducedEntries.toArray()[1].compare("|_ ") == 0);
    CHECK(reducedEntries.toArray()[2].compare("|_|") == 0);
    CHECK(reducedEntries.toArray()[3].compare("   ") == 0);
}


TEST(OCREntries_given_entries_text_of_5_6,
                when_chopping_2_from_back_then_2_columns_will_be_removed) {
	OCREntries reducedEntries(entries.chopFromBack(2));

    CHECK(reducedEntries.toArray()[0].compare("  _ ") == 0);
    CHECK(reducedEntries.toArray()[1].compare(" |_ ") == 0);
    CHECK(reducedEntries.toArray()[2].compare("||_|") == 0);
    CHECK(reducedEntries.toArray()[3].compare("    ") == 0);
}

/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////

TEST_GROUP(OCREntries) {
};

TEST(OCREntries, when_width_is_greater_than_27_chars_then_an_exception_is_thrown) {
    bool ok = true;

    OCRDataArray dataArray;
    std::string arr[] = { " _     _  _     _  _  _  _  _ ",
                          "| |  | _| _||_||_ |_   ||_||_|",
                          "|_|  ||_  _|  | _||_|  ||_| _|",
                          "                              "};
    dataArray = OCRDataArray(arr, arr + 4);

    try {
        OCREntries entries(dataArray);
    } catch(std::invalid_argument& e) {
        ok = false;
    }

    CHECK_EQUAL(false, ok);
}


