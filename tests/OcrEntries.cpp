#include "../src/OcrEntries.h"

#include <CppUTest/TestHarness.h>
#include <tr1/memory>

typedef std::tr1::shared_ptr<OcrEntries> OcrEntriesPtr;

TEST_GROUP(OcrEntries_given_entries_text_of_5_6) {
	OcrEntriesPtr entries;

	void setup() {
		std::string arr[] = { " _  _ ",
							  "|_ |_ ",
						  	  " _||_|",
							  "      "};
		OcrEntriesText entriesText(arr, arr + 4);
		entries.reset(new OcrEntries(entriesText));
	}
};

TEST(OcrEntries_given_entries_text_of_5_6, then_we_can_retrieve_the_inner_text_later) {
	OcrEntriesText entriesText = entries.get()->toArray();
	CHECK(entriesText[0].compare(" _  _ ") == 0);
	CHECK(entriesText[1].compare("|_ |_ ") == 0);
	CHECK(entriesText[2].compare(" _||_|") == 0);
	CHECK(entriesText[3].compare("      ") == 0);
}

TEST(OcrEntries_given_entries_text_of_5_6, then_it_has_a_height_of_4) {
	CHECK_EQUAL(4, entries.get()->Height());
}

