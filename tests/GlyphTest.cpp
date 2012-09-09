#include "../src/Glyph.h"

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
		OcrEntriesText glyphText(arr, arr + 4);
		glyph.reset(new Glyph(glyphText));
	}
};

TEST(Glyph_given_glyph_is_3, when_entry_is_exactly_3_then_it_matches) {
	std::string arr[] = { "_ ",
			              "_|",
			              "_|",
			              "  "};
	OcrEntriesText entries(arr, arr + 4);

	bool isMatch = glyph.get()->MatchBackOfOcrEntries(entries);
	CHECK(isMatch);
}

TEST(Glyph_given_glyph_is_3, when_entry_is_exactly_3_4_then_it_matches) {
	std::string arr[] = { "_     ",
			              "_| |_|",
			              "_|   |",
			              "      "};
	OcrEntriesText entries(arr, arr + 4);

	bool isMatch = glyph.get()->MatchBackOfOcrEntries(entries);
	CHECK(isMatch);
}

TEST(Glyph_given_glyph_is_3, when_entry_is_exactly_4_3_then_it_does_not_match) {
	std::string arr[] = { "    _ ",
			              "|_| _|",
			              "  | _|",
			              "      "};
	OcrEntriesText entries(arr, arr + 4);

	bool isMatch = glyph.get()->MatchBackOfOcrEntries(entries);
	CHECK(!isMatch);
}

TEST(Glyph_given_glyph_is_3, when_entry_is_empty_then_it_does_not_match) {
	std::string arr[] = { "",
			              "",
			              "",
			              ""};
	OcrEntriesText entries(arr, arr + 4);

	bool isMatch = glyph.get()->MatchBackOfOcrEntries(entries);
	CHECK(!isMatch);
}

TEST(Glyph_given_glyph_is_3, when_entry_is_missing_whitespace_then_it_does_not_match) {
	std::string arr[] = { "_ ",
			              "_|",
			              "_|",
			              ""};
	OcrEntriesText entries(arr, arr + 4);

	bool isMatch = glyph.get()->MatchBackOfOcrEntries(entries);
	CHECK(!isMatch);
}

TEST(Glyph_given_glyph_is_3, then_it_has_a_height_of_4) {
	CHECK_EQUAL(4, glyph.get()->Height());
}

TEST(Glyph_given_glyph_is_3, then_it_has_a_width_of_2) {
	CHECK_EQUAL(2, glyph.get()->Width());
}




TEST_GROUP(Glyph_given_glyph_is_6) {
	GlyphPtr glyph;

	void setup() {
		std::string arr[] = { " _ ",
				   			  "|_ ",
							  "|_|",
							  "   "};
		OcrEntriesText glyphText(arr, arr + 4);
		glyph.reset(new Glyph(glyphText));
	}
};

TEST(Glyph_given_glyph_is_6, then_it_has_a_width_of_3) {
	CHECK_EQUAL(3, glyph.get()->Width());
}



TEST_GROUP(Glyph_given_glyph_is_minimal) {
};

TEST(Glyph_given_glyph_is_minimal, when_the_width_is_zero_then_an_exception_is_thrown) {
	bool ok = true;

	OcrEntriesText glyphText;
	std::string arr[] = { "" };
	glyphText = OcrEntriesText(arr, arr + 1);

	try {
		Glyph glyph(glyphText);
	} catch(std::invalid_argument& e) {
		ok = false;
	}

	CHECK_EQUAL(false, ok);
}

TEST(Glyph_given_glyph_is_minimal, when_the_height_is_less_than_4_an_exception_is_thrown) {
	bool ok = true;

	OcrEntriesText glyphText;
	std::string arr[] = { "|",
			              "|",
			              "|" };
	glyphText = OcrEntriesText(arr, arr + 1);

	try {
		Glyph glyph(glyphText);
	} catch(std::invalid_argument& e) {
		ok = false;
	}

	CHECK_EQUAL(false, ok);
}
