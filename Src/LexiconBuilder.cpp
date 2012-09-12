#include "LexiconBuilder.h"
#include "glyph.h"

using namespace std;

LexiconBuilder::LexiconBuilder() {
}

GlyphList LexiconBuilder::build() const {
	GlyphList list;

	list.push_back(buildZeroGlyph());
	list.push_back(buildOneGlyph());
	list.push_back(buildTwoGlyph());
	list.push_back(buildThreeGlyph());
	list.push_back(buildFourGlyph());
	list.push_back(buildFiveGlyph());
	list.push_back(buildSixGlyph());
	list.push_back(buildSevenGlyph());
	list.push_back(buildEightGlyph());
	list.push_back(buildNineGlyph());

	return list;
}

Glyph LexiconBuilder::buildZeroGlyph() const {
    std::string arr[] = { " _ ",
                          "| |",
                          "|_|",
                          "   "};
    OCRDataArray vec(arr, arr + 4);
	return Glyph(vec, "0");
}

Glyph LexiconBuilder::buildOneGlyph() const {
    std::string arr[] = { "   ",
                          "  |",
                          "  |",
                          "   "};
    OCRDataArray vec(arr, arr + 4);
	return Glyph(vec, "1");
}

Glyph LexiconBuilder::buildTwoGlyph() const {
    std::string arr[] = { " _ ",
                          " _|",
                          "|_ ",
                          "   "};
    OCRDataArray vec(arr, arr + 4);
	return Glyph(vec, "2");
}

Glyph LexiconBuilder::buildThreeGlyph() const {
    std::string arr[] = { " _ ",
                          " _|",
                          " _|",
                          "   "};
    OCRDataArray vec(arr, arr + 4);
	return Glyph(vec, "3");
}

Glyph LexiconBuilder::buildFourGlyph() const {
    std::string arr[] = { "   ",
                          "|_|",
                          "  |",
                          "   "};
    OCRDataArray vec(arr, arr + 4);
	return Glyph(vec, "4");
}

Glyph LexiconBuilder::buildFiveGlyph() const {
    std::string arr[] = { " _ ",
                          "|_ ",
                          " _|",
                          "   "};
    OCRDataArray vec(arr, arr + 4);
	return Glyph(vec, "5");
}

Glyph LexiconBuilder::buildSixGlyph() const {
    std::string arr[] = { " _ ",
                          "|_ ",
                          "|_|",
                          "   "};
    OCRDataArray vec(arr, arr + 4);
	return Glyph(vec, "6");
}

Glyph LexiconBuilder::buildSevenGlyph() const {
    std::string arr[] = { " _ ",
                          "  |",
                          "  |",
                          "   "};
    OCRDataArray vec(arr, arr + 4);
	return Glyph(vec, "7");
}

Glyph LexiconBuilder::buildEightGlyph() const {
    std::string arr[] = { " _ ",
                          "|_|",
                          "|_|",
                          "   "};
    OCRDataArray vec(arr, arr + 4);
	return Glyph(vec, "8");
}

Glyph LexiconBuilder::buildNineGlyph() const {
    std::string arr[] = { " _ ",
                          "|_|",
                          " _|",
                          "   "};
    OCRDataArray vec(arr, arr + 4);
	return Glyph(vec, "9");
}

Glyph LexiconBuilder::buildSpaceGlyph() const {
    std::string arr[] = { "   ",
                          "   ",
                          "   ",
                          "   "};
    OCRDataArray vec(arr, arr + 4);
	return Glyph(vec, " ");
}


