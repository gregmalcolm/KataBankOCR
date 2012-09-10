#include "../Src/LexiconBuilder.h"
#include "../Src/Glyph.h"

#include <CppUTest/TestHarness.h>

TEST_GROUP(LexiconBuilder) {
	LexiconBuilder builder;
};

TEST(LexiconBuilder, when_building_0_returns_the_glyph) {
    Glyph const& glyph = builder.buildZeroGlyph();

    CHECK(glyph.toArray()[0].compare(" _ ") == 0);
    CHECK(glyph.toArray()[1].compare("| |") == 0);
    CHECK(glyph.toArray()[2].compare("|_|") == 0);
    CHECK(glyph.toArray()[3].compare("   ") == 0);
}
