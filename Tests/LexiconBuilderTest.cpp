#include "../Src/LexiconBuilder.h"
#include "../Src/Glyph.h"

#include <CppUTest/TestHarness.h>

TEST_GROUP(LexiconBuilder) {
	LexiconBuilder builder;
};

TEST(LexiconBuilder, when_building_0_returns_a_glyph_with_data_of_0) {
    Glyph const& glyph = builder.buildZeroGlyph();

    CHECK(glyph.toArray()[0].compare(" _ ") == 0);
    CHECK(glyph.toArray()[1].compare("| |") == 0);
    CHECK(glyph.toArray()[2].compare("|_|") == 0);
    CHECK(glyph.toArray()[3].compare("   ") == 0);
}

TEST(LexiconBuilder, when_building_1_returns_a_glyph_with_data_of_1) {
    Glyph const& glyph = builder.buildOneGlyph();

    CHECK(glyph.toArray()[0].compare("  |") == 0);
    CHECK(glyph.toArray()[1].compare("  |") == 0);
    CHECK(glyph.toArray()[2].compare("  |") == 0);
    CHECK(glyph.toArray()[3].compare("   ") == 0);
}

TEST(LexiconBuilder, when_building_2_returns_a_glyph_with_data_of_2) {
    Glyph const& glyph = builder.buildTwoGlyph();

    CHECK(glyph.toArray()[0].compare(" _ ") == 0);
    CHECK(glyph.toArray()[1].compare(" _|") == 0);
    CHECK(glyph.toArray()[2].compare("|_ ") == 0);
    CHECK(glyph.toArray()[3].compare("   ") == 0);
}

TEST(LexiconBuilder, when_building_3_returns_a_glyph_with_data_of_3) {
    Glyph const& glyph = builder.buildThreeGlyph();

    CHECK(glyph.toArray()[0].compare(" _ ") == 0);
    CHECK(glyph.toArray()[1].compare(" _|") == 0);
    CHECK(glyph.toArray()[2].compare(" _|") == 0);
    CHECK(glyph.toArray()[3].compare("   ") == 0);
}

TEST(LexiconBuilder, when_building_4_returns_a_glyph_with_data_of_4) {
    Glyph const& glyph = builder.buildFourGlyph();

    CHECK(glyph.toArray()[0].compare("   ") == 0);
    CHECK(glyph.toArray()[1].compare("|_|") == 0);
    CHECK(glyph.toArray()[2].compare("  |") == 0);
    CHECK(glyph.toArray()[3].compare("   ") == 0);
}

TEST(LexiconBuilder, when_building_5_returns_a_glyph_with_data_of_5) {
    Glyph const& glyph = builder.buildFiveGlyph();

    CHECK(glyph.toArray()[0].compare(" _ ") == 0);
    CHECK(glyph.toArray()[1].compare("|_ ") == 0);
    CHECK(glyph.toArray()[2].compare(" _|") == 0);
    CHECK(glyph.toArray()[3].compare("   ") == 0);
}

TEST(LexiconBuilder, when_building_6_returns_a_glyph_with_data_of_6) {
    Glyph const& glyph = builder.buildSixGlyph();

    CHECK(glyph.toArray()[0].compare(" _ ") == 0);
    CHECK(glyph.toArray()[1].compare("|_ ") == 0);
    CHECK(glyph.toArray()[2].compare("|_|") == 0);
    CHECK(glyph.toArray()[3].compare("   ") == 0);
}

TEST(LexiconBuilder, when_building_7_returns_a_glyph_with_data_of_7) {
    Glyph const& glyph = builder.buildSevenGlyph();

    CHECK(glyph.toArray()[0].compare(" _ ") == 0);
    CHECK(glyph.toArray()[1].compare("  |") == 0);
    CHECK(glyph.toArray()[2].compare("  |") == 0);
    CHECK(glyph.toArray()[3].compare("   ") == 0);
}

TEST(LexiconBuilder, when_building_8_returns_a_glyph_with_data_of_8) {
    Glyph const& glyph = builder.buildEightGlyph();

    CHECK(glyph.toArray()[0].compare(" _ ") == 0);
    CHECK(glyph.toArray()[1].compare("|_|") == 0);
    CHECK(glyph.toArray()[2].compare("|_|") == 0);
    CHECK(glyph.toArray()[3].compare("   ") == 0);
}

TEST(LexiconBuilder, when_building_9_returns_a_glyph_with_data_of_9) {
    Glyph const& glyph = builder.buildNineGlyph();

    CHECK(glyph.toArray()[0].compare(" _ ") == 0);
    CHECK(glyph.toArray()[1].compare("|_|") == 0);
    CHECK(glyph.toArray()[2].compare(" _|") == 0);
    CHECK(glyph.toArray()[3].compare("   ") == 0);
}

TEST(LexiconBuilder, when_building_space_returns_a_glyph_with_data_of_space) {
    Glyph const& glyph = builder.buildSpaceGlyph();

    CHECK(glyph.toArray()[0].compare("   ") == 0);
    CHECK(glyph.toArray()[1].compare("   ") == 0);
    CHECK(glyph.toArray()[2].compare("   ") == 0);
    CHECK(glyph.toArray()[3].compare("   ") == 0);
}

TEST(LexiconBuilder, when_building_0_returns_a_glyph_with_value_of_0) {
    Glyph const& glyph = builder.buildZeroGlyph();

    CHECK(glyph.getValue().compare("0") == 0);
}

TEST(LexiconBuilder, when_building_1_returns_a_glyph_with_value_of_1) {
    Glyph const& glyph = builder.buildOneGlyph();

    CHECK(glyph.getValue().compare("1") == 0);
}

TEST(LexiconBuilder, when_building_2_returns_a_glyph_with_value_of_2) {
    Glyph const& glyph = builder.buildTwoGlyph();

    CHECK(glyph.getValue().compare("2") == 0);
}

TEST(LexiconBuilder, when_building_3_returns_a_glyph_with_value_of_3) {
    Glyph const& glyph = builder.buildThreeGlyph();

    CHECK(glyph.getValue().compare("3") == 0);
}

TEST(LexiconBuilder, when_building_4_returns_a_glyph_with_value_of_4) {
    Glyph const& glyph = builder.buildFourGlyph();

    CHECK(glyph.getValue().compare("4") == 0);
}

TEST(LexiconBuilder, when_building_5_returns_a_glyph_with_value_of_5) {
    Glyph const& glyph = builder.buildFiveGlyph();

    CHECK(glyph.getValue().compare("5") == 0);
}

TEST(LexiconBuilder, when_building_6_returns_a_glyph_with_value_of_6) {
    Glyph const& glyph = builder.buildSixGlyph();

    CHECK(glyph.getValue().compare("6") == 0);
}

TEST(LexiconBuilder, when_building_7_returns_a_glyph_with_value_of_7) {
    Glyph const& glyph = builder.buildSevenGlyph();

    CHECK(glyph.getValue().compare("7") == 0);
}

TEST(LexiconBuilder, when_building_8_returns_a_glyph_with_value_of_8) {
    Glyph const& glyph = builder.buildEightGlyph();

    CHECK(glyph.getValue().compare("8") == 0);
}

TEST(LexiconBuilder, when_building_9_returns_a_glyph_with_value_of_9) {
    Glyph const& glyph = builder.buildNineGlyph();

    CHECK(glyph.getValue().compare("9") == 0);
}

TEST(LexiconBuilder, when_building_space_returns_a_glyph_with_value_of_space) {
    Glyph const& glyph = builder.buildSpaceGlyph();

    CHECK(glyph.getValue().compare(" ") == 0);
}

TEST(LexiconBuilder,
	 when_building_everything_then_a_list_of_11_glyphs_are_returned) {
	GlyphList list(builder.build());

	unsigned int noOfGlyphs = list.size();
	CHECK_EQUAL(11, noOfGlyphs);
}
