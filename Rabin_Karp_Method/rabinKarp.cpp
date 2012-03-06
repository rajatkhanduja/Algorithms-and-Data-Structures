/* Program to implement the RabinKarp method 
 * The method is generic and can be used for all types.
 */

#include <iostream>
#include <string>
#include <iterator>
#include <cassert>

using std::string;

template<class InputIterator>
InputIterator rabinKarpSearch (InputIterator stringStart, InputIterator stringEnd, InputIterator patternStart, InputIterator patternEnd);

int main (int argc, char *argv[])
{
  string searchString, pattern;
  std::cin >>  searchString >> pattern;

  std::cout << (rabinKarpSearch (searchString.begin(), searchString.end(), pattern.begin(), pattern.end()) != searchString.end());
}

const int hashBase = 10;

template<class InputIterator>
unsigned int hashFunction (InputIterator start, InputIterator end)
{
  unsigned int val = 0;

  while (start != end)
  {
    val = val * hashBase + *(start++);
  }

  return val;
}

unsigned int hashConst (int patternLength)
{
  unsigned int ans = 1;
  while (patternLength-- > 0)
  {
    ans = ans * hashBase;
  }
  return ans;
}

template <class InputIterator>
bool match (InputIterator stringStart1, InputIterator stringEnd1, InputIterator stringStart2, InputIterator stringEnd2)
{
  assert ( distance (stringStart1, stringEnd1) == distance (stringStart2, stringEnd2) );
  
  for ( ; (stringStart1 != stringEnd1) && (*stringStart1 == *stringStart2); stringStart1++, stringStart2++)
    ;

  if ( stringStart1 == stringEnd1)
    return true;
  else
    return false;
}

template<class InputIterator>
InputIterator rabinKarpSearch (InputIterator stringStart, InputIterator stringEnd, InputIterator patternStart, InputIterator patternEnd)
{

  InputIterator stringPatternLen = stringStart;
  advance (stringPatternLen, distance (patternStart, patternEnd));
  unsigned int searchHash = hashFunction (stringStart, stringPatternLen);
  const unsigned int patternHash =  hashFunction (patternStart, patternEnd);
  
  /* This macro is used to compare hashvalues and if they match, check if its a true or a false postitive */

  #define CMP_HASH() \
  {\
    if (searchHash == patternHash)\
    {\
      if ( match (stringStart, stringPatternLen, patternStart, patternEnd ))\
      {\
        return stringStart;\
      }\
    }\
  }
  
  CMP_HASH();

  stringStart++, stringPatternLen++;

  for ( ;stringStart != stringEnd; stringStart++, stringPatternLen++)
  {
    CMP_HASH();
  }

  return stringEnd;
}
