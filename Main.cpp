#include <CppUTest/CommandLineTestRunner.h>
#include <iostream>
#include "Src/OCRFileLoader.h"

int main(int argc, char **argv) {
	if (argc == 3) {
		std::cout << "Reading OCR file '" << argv[1] <<  "'...\n";
		OCRFileLoader loader(argv[1], argv[2]);
		std::cout << "Writing account file '" << argv[2] <<  "'...\n";
		return 1;
	} else {
		return CommandLineTestRunner::RunAllTests(argc, argv);
	}
}



