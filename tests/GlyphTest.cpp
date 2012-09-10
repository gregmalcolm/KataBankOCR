#include "../Src/Glyph.h"

#include <CppUTest/TestHarness.h>
#include <tr1/memory>
#include <stdexcept>

typedef std::tr1::shared_ptr<Glyph> GlyphPtr;

TEST_GROUP(Glyph_given_glyph_is_3) {
    GlyphPtr glyph;

    void setup() {
        std::string arr[] = { "_ ",
                            "_|",
                            "_|",
                            "  "};
        OCRDataArray glyphArray(arr, arr + 4);
        glyph.reset(new Glyph(glyphArray));
    }
};

TEST(Glyph_given_glyph_is_3, when_entry_is_exactly_3_then_it_matches) {
    std::string arr[] = { "_ ",
                          "_|",
                          "_|",
                          "  "};
    OCRDataArray entries(arr, arr + 4);

    bool isMatch = glyph.get()->MatchBackOfOCREntries(entries);
    CHECK(isMatch);
}

TEST(Glyph_given_glyph_is_3, when_entry_is_exactly_3_4_then_it_matches) {
    std::string arr[] = { "_     ",
                          "_| |_|",
                          "_|   |",
                          "      "};
    OCRDataArray entries(arr, arr + 4);

    bool isMatch = glyph.get()->MatchBackOfOCREntries(entries);
    CHECK(isMatch);
}

TEST(Glyph_given_glyph_is_3, when_entry_is_exactly_4_3_then_it_does_not_match) {
    std::string arr[] = { "    _ ",
                          "|_| _|",
                          "  | _|",
                          "      "};
    OCRDataArray entries(arr, arr + 4);

    bool isMatch = glyph.get()->MatchBackOfOCREntries(entries);
    CHECK(!isMatch);
}

TEST(Glyph_given_glyph_is_3, when_entry_is_empty_then_it_does_not_match) {
    std::string arr[] = { "",
                          "",
                          "",
                          ""};
    OCRDataArray entries(arr, arr + 4);

    bool isMatch = glyph.get()->MatchBackOfOCREntries(entries);
    CHECK(!isMatch);
}

TEST(Glyph_given_glyph_is_3, when_entry_is_missing_whitespace_then_it_does_not_match) {
    std::string arr[] = { "_ ",
                          "_|",
                          "_|",
                          ""};
    OCRDataArray entries(arr, arr + 4);

    bool isMatch = glyph.get()->MatchBackOfOCREntries(entries);
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
