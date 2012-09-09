#include "../src/GlyphTranslator.h"

#include <CppUTest/TestHarness.h>

TEST_GROUP(GlyphTranslator_given_the_constructor_is_9) {
};

TEST(GlyphTranslator_given_the_constructor_is_9, then_the_value_is_9) {
	std::string arr[] = { " _ ",
			              "|_|",
			              " _|",
			              "   "};
	OcrEntriesArray entry(arr, arr + 4);

    GlyphTranslator translator(entry);

	std::string value;
	value = translator.GetValues();
	CHECK_EQUAL(0, value.compare("9"));
};

TEST_GROUP(GlyphTranslator) {
	GlyphTranslator translator;
};

TEST(GlyphTranslator, when_the_entry_is_1_then_the_value_is_1) {
	std::string arr[] = { " ",
			              "|",
			              "|",
			              " " };
	OcrEntriesArray entry(arr, arr + 4);

	translator.SetEntries(entry);

	std::string value;
	value = translator.GetValues();
	CHECK_EQUAL(0, value.compare("1"));
};
