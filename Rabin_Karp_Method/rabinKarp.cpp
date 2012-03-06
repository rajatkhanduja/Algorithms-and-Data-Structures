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

  int test1[] = {1,2,3,4,5,6,7,8};
  int test2[] = {7,8};
  
  rabinKarpSearch (test1, test1 + 8, test2, test2 + 2);
  std::cout << (rabinKarpSearch (searchString.begin(), searchString.end(), pattern.begin(), pattern.end()) != searchString.end());
}

const int hashBase = 10;

inline int distance (int * ptr1, int * ptr2)
{
  return ptr2 - ptr1;
}

inline void advance (int *&ptr, int distance)
{
  ptr += distance;
}

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
  while (patternLength-- > 1)
  {
    ans = ans * hashBase;
  }
  return ans;
}

/* Function tests if two string match */
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
  const unsigned int hashConstant = hashConst (distance (patternStart, patternEnd));
  
  int patternLen         = distance (patternStart, patternEnd);
  int distStringStartEnd = distance (stringStart , stringEnd );

  for ( ; distStringStartEnd-- >= patternLen; stringStart++, stringPatternLen++ )
  {
    /* Test if the hashes match */
    if ( searchHash == patternHash)
    {
      /* Check for false positives */
      if (match (stringStart, stringPatternLen, patternStart, patternEnd))
      {
        return stringStart;
      }
    }
  
    /* Sliding hash */
    searchHash = ( searchHash - (unsigned int)*stringStart * hashConstant) * hashBase + *stringPatternLen;
  }

  return stringEnd;
}
