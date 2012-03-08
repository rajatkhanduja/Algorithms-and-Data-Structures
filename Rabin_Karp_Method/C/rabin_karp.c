/* Program to implement the Rabin Karp Method */

#include <stdio.h>
#include <string.h>

#define STRING_LEN 10000
#define PATTERN_LEN 100

#define _HASH_BASE 10

#define _hash(_str, _len, _hash_val)\
do {\
  unsigned int i;\
  _hash_val = 0;\
  for ( i = 0; i < _len; i++ )\
  {\
    _hash_val = _hash_val * _HASH_BASE + _str[i];\
  }\
} while (0)

/* TODO : Think of a better name for this function */
#define _hash_const(_n, _var)\
{\
  unsigned int i = _n;\
  _var = 1;\
  while ( i-- > 0)\
  {\
    _var = _var * _HASH_BASE;\
  }\
}

#define _match(_string, _pattern, _len_pattern, _is_match)\
{\
  unsigned int i, j, tmp = _len_pattern;\
  /* Using two variables i & j with the intent to allow independent increments. */\
  for (i = 0, j =0; tmp-- > 0; i++, j++)\
  {\
    if (string[i] != pattern[j])\
    {\
      _is_match = 0;\
      break;\
    }\
  }\
  _is_match = 1;\
} 


#define string_search(_string, _len_string, _pattern, _len_pattern, _ret) \
do {\
  unsigned int _pattern_hash, _string_hash; \
  _hash(_pattern, _len_pattern, _pattern_hash);\
  _hash(_string,  _len_pattern,  _string_hash);\
  unsigned int i, _shift_const;\
  _hash_const (_len_pattern - 1, _shift_const);\
  char _matches = 0;\
  _ret = -1;\
\
  for ( i = 0; i < _len_string - _len_pattern + 1; i++)\
  {\
    if ( i != 0)\
      _string_hash = (_string_hash - (_string[i - 1] * _shift_const)) * _HASH_BASE + _string[i + _len_pattern - 1];\
    \
    if ( _pattern_hash == _string_hash )\
    {\
      _match (_string + i, _pattern, _len_pattern, _matches);\
      if (_matches)\
        _ret = i; break;\
    }\
  }\
\
} while(0)


int main (int argc, char *argv[])
{
  char string[STRING_LEN]; 
  char pattern[STRING_LEN];

  scanf ("%s %s", string, pattern);

  unsigned int t;
  string_search(string, strlen(string), pattern, strlen(pattern), t);

  printf ("%d\n", t);

  return 0;
}
