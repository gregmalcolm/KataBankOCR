#include "../Src/OCREntries.h"

#include <CppUTest/TestHarness.h>
#include <tr1/memory>

typedef std::tr1::shared_ptr<OCREntries> OCREntriesPtr;

TEST_GROUP(OCREntries_given_entries_text_of_5_6) {
    OCREntriesPtr entries;

    void setup() {
        std::string arr[] = { " _  _ ",
                              "|_ |_ ",
                              " _||_|",
                              "      "};
        OCRDataArray entriesArray(arr, arr + 4);
        entries.reset(new OCREntries(entriesArray));
    }
};
