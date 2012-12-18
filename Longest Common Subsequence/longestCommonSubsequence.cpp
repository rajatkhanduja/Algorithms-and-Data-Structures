#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;


string longestCommonSubsequence (string s1, string s2)
{
  vector<vector<int> > lcs (s1.size() + 1, vector<int>(s2.size() + 1, 0));
  int i, j;

  for (i = 1; i <= s1.size(); i++)
  {
    for (j = 1; j <= s2.size(); j++)
    {
      if (s1[i - 1] == s2[j - 1])
        lcs[i][j] = lcs[i - 1][j - 1] + 1;
      else
        lcs[i][j] = max (lcs[i - 1][j], lcs[i][j - 1]);
    }
  }
  
  /* Obtain the subsequence */
  int subsequenceLength = lcs[s1.size()][s2.size()];

  if (subsequenceLength == 0)
    return string();

  string subsequence(subsequenceLength, '-');
  int k = subsequenceLength - 1;
  for (i = s1.size(), j = s2.size(); !(i == 0 && j == 0); )
  {
    if (lcs[i - 1][j] == lcs[i][j])
    {
      i--;
    }
    else if (lcs[i][j - 1] == lcs[i][j])
    {
      j--;
    }
    else
    {
      i--, j--;
      assert (s1[i] == s2[j]);
      subsequence[k--] = s1[i];
    }
  }
  
//  reverse (subsequence.begin(), subsequence.end());
  return subsequence;
}

int main (void)
{
  string s1, s2;
  cin >> s1 >> s2;
  cout << longestCommonSubsequence (s1, s2) << endl;
  return 0;
}
