#include "LexiconBuilder.h"
#include "glyph.h"

LexiconBuilder::LexiconBuilder() {
}

Glyph LexiconBuilder::buildZeroGlyph() {
    std::string arr[] = { " _ ",
                          "| |",
                          "|_|",
                          "   "};
    OCRDataArray vec(arr, arr + 4);
	return Glyph(vec);
}
