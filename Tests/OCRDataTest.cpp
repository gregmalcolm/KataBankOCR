#include "../Src/OCRData.h"
#include "Fakes/ConcreteOCRData.h"

#include <CppUTest/TestHarness.h>
#include <tr1/memory>
#include <stdexcept>

typedef std::tr1::shared_ptr<ConcreteOCRData> OCRDataPtr;

TEST_GROUP(OCRData_given_entries_text_of_7_8) {
	OCRDataPtr data;

	void setup() {
		std::string arr[] = { " _  _ ",
							  "  ||_|",
						  	  "  ||_|",
							  "      "};
		OCRDataArray dataArray(arr, arr + 4);
		data.reset(new ConcreteOCRData(dataArray));
	}
};

TEST(OCRData_given_entries_text_of_7_8, then_we_can_retrieve_the_inner_text_later) {
	OCRDataArray dataArray = data.get()->toArray();
	CHECK(dataArray[0].compare(" _  _ ") == 0);
	CHECK(dataArray[1].compare("  ||_|") == 0);
	CHECK(dataArray[2].compare("  ||_|") == 0);
	CHECK(dataArray[3].compare("      ") == 0);
}

TEST(OCRData_given_entries_text_of_7_8, then_it_has_a_height_of_4) {
	CHECK_EQUAL(4, data.get()->Height());
}

TEST(OCRData_given_entries_text_of_7_8, then_it_has_a_width_of_6) {
	CHECK_EQUAL(6, data.get()->Width());
}

TEST_GROUP(OCRData_given_entries_text_of_2) {
	OCRDataPtr data;

	void setup() {
		std::string arr[] = { " _ ",
							  " _|",
						  	  "|_ ",
							  "   "};
		OCRDataArray dataArray(arr, arr + 4);
		data.reset(new ConcreteOCRData(dataArray));
	}
};

TEST(OCRData_given_entries_text_of_2, then_it_has_a_width_of_3) {
	CHECK_EQUAL(3, data.get()->Width());
}


TEST_GROUP(OCRData_given_data_is_minimal) {
};

TEST(OCRData_given_data_is_minimal, when_the_width_is_zero_then_an_exception_is_thrown) {
	bool ok = true;

	OCRDataArray dataArray;
	std::string arr[] = { "" };
	dataArray = OCRDataArray(arr, arr + 1);

	try {
		ConcreteOCRData data(dataArray);
	} catch(std::invalid_argument& e) {
		ok = false;
	}

	CHECK_EQUAL(false, ok);
}

TEST(OCRData_given_data_is_minimal, when_the_height_is_less_than_4_an_exception_is_thrown) {
	bool ok = true;

	OCRDataArray dataArray;
	std::string arr[] = { "|",
			              "|",
			              "|" };
	dataArray = OCRDataArray(arr, arr + 1);

	try {
		ConcreteOCRData data(dataArray);
	} catch(std::invalid_argument& e) {
		ok = false;
	}

	CHECK_EQUAL(false, ok);
}
