#include "../Src/OCREntries.h"

#include <CppUTest/TestHarness.h>
#include <tr1/memory>

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
                when_chopping_3_from_back_then_3_columns_will_be_removed) {
	OCREntries reducedEntries(entries.chopFromBack(3));

    CHECK(reducedEntries.toArray()[0].compare(" _ ") == 0);
    CHECK(reducedEntries.toArray()[1].compare("|_ ") == 0);
    CHECK(reducedEntries.toArray()[2].compare("|_|") == 0);
    CHECK(reducedEntries.toArray()[3].compare("   ") == 0);
}
