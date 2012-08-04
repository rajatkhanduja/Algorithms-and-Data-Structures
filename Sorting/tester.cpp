#include <iostream>
#include <sort.h>

int main (void)
{
  int n, i;
  std::cin >> n;
  
  vector <int> numbers(n);

  for (i = 0; i < n; i++)
  {
    std::cin >> numbers[i];
  }

  quickSort(numbers);

  for (i = 0; i < n; i++)
  {
    std::cout << numbers[i] << std::endl;
  }

  return 0;
}
