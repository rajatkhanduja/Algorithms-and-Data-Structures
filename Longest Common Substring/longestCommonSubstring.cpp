#include <iostream>
#include <string>
#include <cassert>

using namespace std;

string longestCommonString (string s1, string s2)
{
  int **lcs = new int*[s1.size() + 1];

  assert (lcs);
  
  int i, j;
  for (i = 0; i < s1.size() + 1; i++)
  {
    lcs[i] = new int[s2.size() + 1];
    assert (lcs[i]);
    if (i == 0)
    {
      for (j = 0; j < s2.size() + 1; j++)
      {
        lcs[i][j] = 0;
      }
    }
    else
    {
      lcs[i][0] = 0;    
    }
  }
  
  int maxVal = 0, maxValI = -1, maxValJ = -1;
  for (i = 1; i < s1.size() + 1; i++)
  {
    for (j = 1; j < s2.size() + 1; j++)
    {
      if (s1[i - 1] == s2[j - 1])
      {
        lcs[i][j] = 1 + lcs[i - 1][j - 1];
        if (lcs[i][j] > maxVal)
        {
          maxVal  = lcs[i][j];
          maxValI = i;
          maxValJ = j;
        }
      }
      else
      {
        lcs[i][j] = 0;
      }
    }
  }

  /* Now, maxVal is the length of the common substring
   * Now, find the string using i,j location of maxVal
   */

  i = maxValI; 
  j = maxValJ;
 
  while (lcs[i--][j--])
    ;

  /* Now moving along i + 1, j + 1 until maxValI,maxValJ we 
   * get the longest common substring.
   */
  i++; j++;  
  string longestCommon;

  while (i != maxValI)
  { 
    longestCommon.append (1, s1[i++]);
  }

  return longestCommon;
}

int main (void)
{
  string s1, s2;
  cin >> s1 >> s2;
  cout << longestCommonString (s1, s2) << endl;
  return 0;
}
