#pragma once
#include <iostream>
#include <vector>
#include <string>

typedef std::vector<std::string> EntriesText;

class GlyphTranslator {
public:
	GlyphTranslator();
	GlyphTranslator(const EntriesText&entries);
	virtual ~GlyphTranslator();

	void SetEntries(EntriesText const entries);

	std::string GetValues();

private:
	std::string values;
};
