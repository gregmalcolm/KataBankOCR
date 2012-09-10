#include "../Src/standard.h"

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
        glyph.reset(new Glyph(glyphArray));
    }
};

TEST(Glyph_given_glyph_is_3, when_entry_is_exactly_3_then_it_matches) {
    std::string arr[] = { " _ ",
                          " _|",
                          " _|",
                          "   "};
    OCRDataArray dataArray(arr, arr + 4);
    OCREntries entries(dataArray);

    bool isMatch = glyph.get()->matchBackOfOCREntries(entries);
    CHECK(isMatch);
}

TEST(Glyph_given_glyph_is_3, when_entry_is_exactly_3_4_then_it_matches) {
    std::string arr[] = { " _    ",
                          " _||_|",
                          " _|  |",
                          "      "};
    OCRDataArray dataArray(arr, arr + 4);
    OCREntries entries(dataArray);

    bool isMatch = glyph.get()->matchBackOfOCREntries(entries);
    CHECK(isMatch);
}

TEST(Glyph_given_glyph_is_3, when_entry_is_exactly_4_3_then_it_does_not_match) {
    std::string arr[] = { "    _ ",
                          "|_| _|",
                          "  | _|",
                          "      "};
    OCRDataArray dataArray(arr, arr + 4);
    OCREntries entries(dataArray);

    bool isMatch = glyph.get()->matchBackOfOCREntries(entries);
    CHECK(!isMatch);
}

TEST(Glyph_given_glyph_is_3, when_entry_is_not_3_the_remainder_is_3) {
    std::string arr[] = { " _ ",
                          " _|",
                          " _|",
                          "   "};
    OCRDataArray dataArray(arr, arr + 4);
    OCREntries entries(dataArray);
    OCREntries remainder;

    glyph.get()->matchBackOfOCREntries(entries, remainder);
    CHECK(remainder.width() == 3);
}

TEST(Glyph_given_glyph_is_3, when_entry_is_empty_then_it_does_not_match) {
    std::string arr[] = { "",
                          "",
                          "",
                          ""};
    OCRDataArray dataArray(arr, arr + 4);
    OCREntries entries(dataArray);

    bool isMatch = glyph.get()->matchBackOfOCREntries(entries);
    CHECK(!isMatch);
}

TEST_GROUP(Glyph_given_glyph_is_6) {
    GlyphPtr glyph;

    void setup() {
        std::string arr[] = { " _ ",
                              "|_ ",
                              "|_|",
                              "   "};
        OCRDataArray glyphArray(arr, arr + 4);
        glyph.reset(new Glyph(glyphArray));
    }
};

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
        Glyph glyph(dataArray);
    } catch(std::invalid_argument& e) {
        ok = false;
    }

    CHECK_EQUAL(false, ok);
}
