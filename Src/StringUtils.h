#pragma once

#include <vector>
#include <list>
#include <string>

typedef std::vector<std::string> StringArray;
typedef StringArray::iterator StringArrayIter;
typedef StringArray::const_iterator StringArrayCIter;

typedef std::list<std::string> StringList;
typedef StringList::iterator StringListIter;
typedef StringList::const_iterator StringListCIter;

inline std::string rtrim(
  const std::string& s,
  const std::string& delimiters = " \f\n\r\t\v" )
{
  return s.substr( 0, s.find_last_not_of( delimiters ) + 1 );
}
