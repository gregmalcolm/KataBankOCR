#include "../Src/Standard.h"
#include "../Src/Glyph.h"
#include "../Src/OCREntries.h"

#include <CppUTest/TestHarness.h>
#include <tr1/memory>
#include <stdexcept>
#include <iostream>

typedef std::tr1::shared_ptr<Glyph> GlyphPtr;

TEST_GROUP(Glyph_given_glyph_is_3) {
    GlyphPtr glyph;

    void setup() {
        std::string arr[] = { " _ ",
                              " _|",
                              " _|",
                              "   "};
        OCRDataArray glyphArray(arr, arr + 4);
        glyph.reset(new Glyph(glyphArray, "3"));
    }
};

TEST(Glyph_given_glyph_is_3,
		   then_value_is_3) {
    std::string value(glyph.get()->getValue());
    CHECK_EQUAL(value.compare("3"), 0);
}

TEST(Glyph_given_glyph_is_3,
		   when_the_value_is_set_as_three_then_the_value_becomes_three) {
	Glyph* gly(glyph.get());
	gly->setValue("three");
    CHECK_EQUAL(gly->getValue().compare("three"), 0);
}


TEST(Glyph_given_glyph_is_3,
		   when_entry_is_exactly_3_then_it_matches) {
    std::string arr[] = { " _ ",
                          " _|",
                          " _|",
                          "   "};
    OCRDataArray dataArray(arr, arr + 4);
    OCREntries entries(dataArray);

    bool isMatch = glyph.get()->matchBackOfOCREntries(entries);
    CHECK(isMatch);
}

TEST(Glyph_given_glyph_is_3,
		   when_entry_is_3_the_remainder_is_nothing) {
    std::string arr[] = { " _ ",
                          " _|",
                          " _|",
                          "   "};
    OCRDataArray dataArray(arr, arr + 4);
    OCREntries entries(dataArray);
    OCREntries remainder;

    glyph.get()->matchBackOfOCREntries(entries, remainder);
    CHECK_EQUAL(0, remainder.width());
}

TEST(Glyph_given_glyph_is_3,
		   when_entry_is_exactly_3_4_then_it_matches) {
    std::string arr[] = { " _    ",
                          " _||_|",
                          " _|  |",
                          "      "};
    OCRDataArray dataArray(arr, arr + 4);
    OCREntries entries(dataArray);

    bool isMatch = glyph.get()->matchBackOfOCREntries(entries);
    CHECK(isMatch);
}

TEST(Glyph_given_glyph_is_3,
		   when_entry_is_exactly_4_3_then_it_does_not_match) {
    std::string arr[] = { "    _ ",
                          "|_| _|",
                          "  | _|",
                          "      "};
    OCRDataArray dataArray(arr, arr + 4);
    OCREntries entries(dataArray);

    bool isMatch = glyph.get()->matchBackOfOCREntries(entries);
    CHECK(!isMatch);
}

TEST(Glyph_given_glyph_is_3,
		   when_entry_is_0_the_remainder_is_0) {
    std::string arr[] = { " _ ",
                          "| |",
                          "|_|",
                          "   "};
    OCRDataArray dataArray(arr, arr + 4);
    OCREntries entries(dataArray);
    OCREntries remainder;

    glyph.get()->matchBackOfOCREntries(entries, remainder);
    CHECK(remainder.toArray()[0].compare(" _ ") == 0);
    CHECK(remainder.toArray()[1].compare("| |") == 0);
    CHECK(remainder.toArray()[2].compare("|_|") == 0);
    CHECK(remainder.toArray()[3].compare("   ") == 0);
}

TEST(Glyph_given_glyph_is_3,
		   when_entry_is_empty_then_it_does_not_match) {
    std::string arr[] = { "",
                          "",
                          "",
                          ""};
    OCRDataArray dataArray(arr, arr + 4);
    OCREntries entries(dataArray);

    bool isMatch = glyph.get()->matchBackOfOCREntries(entries);
    CHECK(!isMatch);
}


////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////


TEST_GROUP(Glyph_given_glyph_is_6) {
    GlyphPtr glyph;

    void setup() {
        std::string arr[] = { " _ ",
                              "|_ ",
                              "|_|",
                              "   "};
        OCRDataArray glyphArray(arr, arr + 4);
        glyph.reset(new Glyph(glyphArray, "6"));
    }
};


////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////


TEST_GROUP(Glyph) {
};

TEST(Glyph, when_the_width_is_zero_then_an_exception_is_thrown) {
    bool ok = true;

    OCRDataArray dataArray;
    std::string arr[] = { "",
                          "",
                          "",
                          "" };
    dataArray = OCRDataArray(arr, arr + 4);

    try {
        Glyph glyph(dataArray, "");
    } catch(std::invalid_argument& e) {
        ok = false;
    }

    CHECK_EQUAL(false, ok);
}
