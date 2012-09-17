KataBankOCR (C++)
=================

Working through this kata in C++:

http://codingdojo.org/cgi-bin/wiki.pl?KataBankOCR

Configuration
-------------

I'm working through this on Mac OS Lion, using GCC 4.2.1 using Eclipe Juno CDT


Setup
-----

run 'setup' to install CppUTest to the Externals folder (if you need to)

*Includes*
Configure Includes to include CppUTest/include and Stl headers (I'm using /usr/include/c++/4.2.1/ )

*Libs*
Also add a lib for CppUTest/lib

Running it
----------

KataBankOCR <input ocr files>, <output accounts numbers files>

*Example:*
  $ Debug/KataBankOCR SampleTestFiles/sample_ocr_file SampleTestFiles/account_numbers

If you just want to see the test suite run, execute it without an arguments. Eg:

  $ Debug/KataBankOCR

