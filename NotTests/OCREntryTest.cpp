#include "../Src/OCREntry.h"

#include <CppUTest/TestHarness.h>
#include <tr1/memory>
#include <stdexcept>

typedef std::tr1::shared_ptr<OCREntry> OCREntryPtr;

TEST_GROUP(OCREntry_given_entry_text_of_5_6) {
    OCREntry entry;

    void setup() {
        std::string arr[] = { " _  _ ",
                              "|_ |_ ",
                              " _||_|",
                              "      "};
        OCRDataArray entryArray(arr, arr + 4);
        entry.setData(entryArray);
    }
};

TEST(OCREntry_given_entry_text_of_5_6,
                when_chopping_from_back_then_3_columns_will_be_removed) {
	OCREntry reducedEntry(entry.chopFromBack());

    CHECK(reducedEntry.toArray()[0].compare(" _ ") == 0);
    CHECK(reducedEntry.toArray()[1].compare("|_ ") == 0);
    CHECK(reducedEntry.toArray()[2].compare("|_|") == 0);
    CHECK(reducedEntry.toArray()[3].compare("   ") == 0);
}


TEST(OCREntry_given_entry_text_of_5_6,
                when_chopping_2_from_back_then_2_columns_will_be_removed) {
	OCREntry reducedEntry(entry.chopFromBack(2));

    CHECK(reducedEntry.toArray()[0].compare("  _ ") == 0);
    CHECK(reducedEntry.toArray()[1].compare(" |_ ") == 0);
    CHECK(reducedEntry.toArray()[2].compare("||_|") == 0);
    CHECK(reducedEntry.toArray()[3].compare("    ") == 0);
}

/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////

TEST_GROUP(OCREntry) {
};

TEST(OCREntry, when_width_is_greater_than_27_chars_then_an_exception_is_thrown) {
    bool ok = true;

    OCRDataArray dataArray;
    std::string arr[] = { " _     _  _     _  _  _  _  _ ",
                          "| |  | _| _||_||_ |_   ||_||_|",
                          "|_|  ||_  _|  | _||_|  ||_| _|",
                          "                              "};
    dataArray = OCRDataArray(arr, arr + 4);

    try {
        OCREntry entry(dataArray);
    } catch(std::invalid_argument& e) {
        ok = false;
    }

    CHECK_EQUAL(false, ok);
}


